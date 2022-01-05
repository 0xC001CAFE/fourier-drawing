#pragma once

struct Color {
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;

	Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 0xff);
};

const Color white(0xff, 0xff, 0xff);
const Color black(0x00, 0x00, 0x00);
