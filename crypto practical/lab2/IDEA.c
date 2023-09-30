/*
    1 hex value = 4 bits
    int = 32 bits
    long = 64 bits
*/

#include<stdio.h>

typedef unsigned long long ull;
typedef unsigned int ui;

unsigned short r_key[56] = { 0 };
unsigned short d_key[56] = { 0 };

void make_rkeys(ull key1, ull key2) {
    // printf("%llX\n", key1);
    for (int i = 0; i <= 8; i++) { // 8 rounds of key generation
        for (int j = 0; j < 4; j++) {
            r_key[8 * i + j] = key1 >> ((16 * (3 - j)) & 0xFFFF);
            r_key[8 * i + j + 4] = key2 >> ((16 * (3 - j)) & 0xFFFF);
            // printf("%llX\n", r_key[j]);
        }

        ull first25 = key1 >> 39;
        ull second25 = key2 >> 39;
        key1 <<= 25;
        key2 <<= 25;
        key1 |= second25;
        key2 |= first25;

        // printf("%llX\n", key1);
        // printf("%llX\n", key2);
    }
}

ui add_modulo(ui a, ui b) {
    // printf("a: %lx\n", a);
    // printf("b: %lx\n", b);
    ui result = (a + b) % 65536;//2^16 = 65536
    // printf("result = %llx\n", result);
    return result;
    // (1 << 16)
}

ui mul_modulo(ui a, ui b) {
    ui result = (a * b) % 65537;
    return result;
}

ull make_ull(ui a, ui b, ui c, ui d) {
    ull result = 0;
    result = ((ull)a) << 48;
    result |= ((ull)b) << 32;
    result |= ((ull)c) << 16;
    result |= ((ull)d);
    // printf("==\n");
    // printf("make ull %llX\n", result);
    return result;
}

// why change to ui, just do short
ull half_round(ull PT) {
    ui a = (ui)(PT >> 48);
    ui b = (ui)(PT >> 32 & 0xFFFF);
    ui c = (ui)(PT >> 16 & 0xFFFF);
    ui d = (ui)(PT & 0xFFFF);
    ui temp = b;
    b = c;
    c = temp;

    a = mul_modulo(a, r_key[48]);
    b = add_modulo(b, r_key[49]);
    c = add_modulo(c, r_key[50]);
    d = mul_modulo(d, r_key[51]);

    return make_ull(a, b, c, d);
}

ull full_round(ull PT, int round_no) {
    // round no starts from 0
    // printf("%llX\n", PT);
    ui a = (ui)(PT >> 48);
    ui b = (ui)(PT >> 32 & 0xFFFF);
    ui c = (ui)(PT >> 16 & 0xFFFF);
    ui d = (ui)(PT & 0xFFFF);
    // time for the 12 step program
    a = mul_modulo(a, r_key[round_no * 6]);
    b = add_modulo(b, r_key[round_no * 6 + 1]);
    c = add_modulo(c, r_key[round_no * 6 + 2]);
    d = mul_modulo(d, r_key[round_no * 6 + 3]);
    ui foo = a ^ c;
    ui bar = b ^ d;
    foo = mul_modulo(foo, r_key[round_no * 6 + 4]);
    bar = add_modulo(bar, foo);
    bar = mul_modulo(bar, r_key[round_no * 6 + 5]);
    foo = add_modulo(foo, bar);
    a ^= bar;
    c ^= bar;
    b ^= foo;
    d ^= foo;
    // ui temp = b;
    // b = c;
    // c = temp;
    // printf("%X\t%X\t%X\t%X\n", a, b, c, d);
    if (round_no == 7)
        return make_ull(a, c, b, d);
    else
        return make_ull(a, b, c, d);
}

ui m_sum_invr(ui a) {
    return 65536 - a;
}
ui m_mul_invr(ui a) {
    ui m0 = 65537;
    ui m = m0;
    ui y = 0;
    ui x = 1;
    while (a > 1) {
        ui q = a / m;
        ui t = m;

        m = a % m;
        a = t;
        t = y;

        y = x - q * y;
        x = t;
    }
    if (x < 0) {
        x += m0;
    }
    return x;
}

void decrypt_mode() {
    printf("Decr mode selected\n");
    int counter = 0;
    for (int i = 0; i < 8; i++) {
        int step = i * 6;
        int l_indx = 46 - step;

        d_key[counter++] = m_mul_invr(r_key[l_indx + 2]);
        int tmp1 = 4;
        int tmp2 = 3;
        if (i == 0) {
            tmp1 = 3;
            tmp2 = 4;
        }
        d_key[counter++] = m_sum_invr(r_key[l_indx + tmp1]);
        d_key[counter++] = m_sum_invr(r_key[l_indx + tmp2]);

        d_key[counter++] = m_mul_invr(r_key[l_indx + 5]);
        d_key[counter++] = r_key[l_indx];
        d_key[counter++] = r_key[l_indx + 1];
    }

    d_key[counter++] = m_mul_invr(r_key[0]);
    d_key[counter++] = m_sum_invr(r_key[1]);
    d_key[counter++] = m_sum_invr(r_key[2]);
    d_key[counter++] = m_mul_invr(r_key[3]);

    for (int i = 0; i < 56; i++) {
        r_key[i] = d_key[i];
    }
}

int main() {

    ull key1 = 0xAB123456789ABCDE;
    ull key2 = 0xABCDEF1234567890;
    // ull key1 = 0;
    // ull key2 = 1;
    make_rkeys(key1, key2);
    char mode = 'w';// d for decrytp
    if (mode == 'd') decrypt_mode();

    // ull PT = 0x96420;
    // ull PT = 0x9FBE020D0000;
    ull PT = 0xD803D55AD38EDB66;

    printf("PT:  %llX\n", PT);
    printf("Key: %llX\t %llX\n", key1, key2);

    for (int i = 0; i < 8; i++) {
        PT = full_round(PT, i);
        // printf("PT - %llX\n", PT);
    }
    PT = half_round(PT);
    printf("Encr %llX\n", PT);
    // printf("rkey0 = %llx", r_key[0]);
    return 0;
}