/* Wrapper for setting errno.
 *
 * Copyright (C) 2000-2006 Erik Andersen <andersen@uclibc.org>
 *
 * Licensed under the LGPL v2.1, see the file COPYING.LIB in this tarball.
 */

#include <errno.h>
#include <features.h>

/* This routine is jumped to by all the syscall handlers, to stash
 * an error number into errno.  */
long __syscall_error(void) attribute_hidden;
long __syscall_error(void)
{
	register int err_no __asm__ ("%rcx");
	__asm__ ("mov %rax, %rcx\n\t"
	         "neg %rcx");
	__set_errno(err_no);
	return -1;
}