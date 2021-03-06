AC_INIT([Dovecot FTS Flatcurve], [0.1.0], [slusarz@curecanti.org], [dovecot-fts-flatcurve])
AC_CONFIG_AUX_DIR([.])
AC_CONFIG_SRCDIR([src])
AC_CONFIG_MACRO_DIR([m4])

AC_CONFIG_HEADERS([dummy-config.h])

AC_DEFINE_UNQUOTED(FTS_FLATCURVE_NAME, "$PACKAGE_NAME",
    [Define to the full name of Dovecot FTS Flatcurve.])
AC_DEFINE_UNQUOTED(FTS_FLATCURVE_VERSION, "$PACKAGE_VERSION",
    [Define to the version of Dovecot FTS Flatcurve.])

AM_INIT_AUTOMAKE([no-define foreign tar-ustar])
AM_MAINTAINER_MODE
AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_LIBTOOL

PKG_PROG_PKG_CONFIG

DC_DOVECOT
DC_DOVECOT_MODULEDIR
LIBDOVECOT_INCLUDE="$LIBDOVECOT_INCLUDE"
CFLAGS="$CFLAGS $EXTRA_CFLAGS"
LIBS="$DOVECOT_LIBS"
AC_SUBST(LIBDOVECOT_INCLUDE)

AC_CHECK_PROG(XAPIAN_CONFIG, xapian-config, xapian-config, no)
if test "x$XAPIAN_CONFIG" = "xno"; then
    AC_MSG_ERROR("xapian could not be found")
fi

XAPIAN_VERSION=$($XAPIAN_CONFIG --version | sed -e 's/.* //')
AS_CASE([$XAPIAN_VERSION],
    [1.[[4-9]].[[0-9]]*],
    [AC_DEFINE([XAPIAN_HAVE_OP_WILDCARD],[1],[Xapian::Query::OP_WILDCARD?])],
    [AC_MSG_ERROR("xapian version >= 1.4 needed; version $XAPIAN_VERSION found.")])

XAPIAN_CXXFLAGS="$($XAPIAN_CONFIG --cxxflags)"
XAPIAN_LIBS="$($XAPIAN_CONFIG --libs)"

AC_SUBST(XAPIAN_CXXFLAGS)
AC_SUBST(XAPIAN_LIBS)

if test "$DOVECOT_INSTALLED" != "yes"; then
    DOVECOT_FTS_PLUGIN="$abs_dovecotdir/src/plugins/fts/lib20_fts_plugin.la"
else
    DOVECOT_FTS_PLUGIN="$dovecot_installed_moduledir/lib20_fts_plugin.la"
fi
AC_SUBST(DOVECOT_FTS_PLUGIN)

AC_CONFIG_FILES([
Makefile
src/Makefile
stamp.h])

AC_OUTPUT

