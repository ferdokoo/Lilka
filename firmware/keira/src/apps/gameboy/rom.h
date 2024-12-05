#ifndef ROM_H
#define ROM_H
#ifdef __cplusplus

extern "C" {

#endif
// int gb_rom_load(const char *);
int gb_rom_init(const unsigned char *);
const unsigned char *gb_rom_getbytes(void);
unsigned int gb_rom_get_mapper(void);

enum {
	NROM,
	MBC1,
	MBC2,
	MMM01,
	MBC3,
	MBC4,
	MBC5,
};
#ifdef __cplusplus

  }

#endif /* end of __cplusplus */
#endif
