
/* Supportability Common Utils file
 * Copyright (C) 2016 Hewlett Packard Enterprise Development LP
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * File: supportability_utils.h
 *
 * Purpose: header file for supportability common utils
 */

#ifndef _SUPPORTABILITY_UTILS_H_
#define _SUPPORTABILITY_UTILS_H_
#include <stdio.h>
#include <string.h>
#include <regex.h>
#include <ctype.h>
#define FREE(X)                  if(X) { free(X); X=NULL;}

#define  STR_SAFE(X)\
        if (sizeof(X) >=  1 )   X[ sizeof(X) - 1 ] =  '\0' ;

#define MAX_STR_BUFF_LEN           512

/* compile the regular expression for the given pattern */
int
compile_corefile_pattern (regex_t * regexst, const char * pattern);

/* strcmp with null check of arguments */
int strcmp_with_nullcheck( const char * str1, const char * str2 );

/* strncmp with null check of arguments */
int strncmp_with_nullcheck( const char * str1, const char * str2, size_t num);

/* strdup with null check of arguments */
char * strdup_with_nullcheck( const char * str1);

/* remove the whitespace characters around the string */
char *
trim_white_space(char *string);

/* Parse journal returned value */
const char*
get_value(const char *str);

/* Convert severity string to values */
int
sev_level(char *arg);

/* Convert from lower to upper case */
char*
strnupr(char *str, int size);

/* Convert from upper to lower case */
char*
strnlwr(char *str, int size);

/* validate cli arguments using regular expression */
int
validate_cli_args(const char * arg , const char * regex);

/* populates jsonrpc client structure for a daemon */
struct jsonrpc*
connect_to_daemon(const char *target);

#endif /* _SUPPORTABILITY_UTILS_H_ */
