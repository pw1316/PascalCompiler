#ifndef __SCAN_H__
#define __SCAN_H__

#define MAXTOKENLEN 40

extern char tokenString[MAXTOKENLEN+1];

TokenType getToken(void);

#endif