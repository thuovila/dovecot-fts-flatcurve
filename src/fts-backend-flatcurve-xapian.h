/* Copyright (c) 2020 Michael Slusarz <slusarz@curecanti.org>
 * See the included COPYING file */

#ifndef FTS_BACKEND_FLATCURVE_XAPIAN_H
#define FTS_BACKEND_FLATCURVE_XAPIAN_H

struct fts_flatcurve_xapian_uid_iterate_context;

struct flatcurve_xapian *fts_flatcurve_xapian_init();
void fts_flatcurve_xapian_deinit(struct flatcurve_xapian *xapian);
void fts_flatcurve_xapian_close(struct flatcurve_fts_backend *backend);
void fts_flatcurve_xapian_get_last_uid(struct flatcurve_fts_backend *backend,
				       uint32_t *last_uid_r);
/* Return -1 if DB doesn't exist, 0 if UID doesn't exist, 1 if UID exists */
int fts_flatcurve_xapian_uid_exists(struct flatcurve_fts_backend *backend,
				    uint32_t uid);
void fts_flatcurve_xapian_expunge(struct flatcurve_fts_backend *backend,
				  uint32_t uid);
void
fts_flatcurve_xapian_index_header(struct flatcurve_fts_backend_update_context *ctx,
				  struct flatcurve_fts_backend *backend,
				  const unsigned char *data, size_t size);
void
fts_flatcurve_xapian_index_body(struct flatcurve_fts_backend_update_context *ctx,
				struct flatcurve_fts_backend *backend,
				const unsigned char *data, size_t size);
void fts_flatcurve_xapian_optimize_box(struct flatcurve_fts_backend *backend);
bool fts_flatcurve_xapian_build_query(struct flatcurve_fts_backend *backend,
				      struct flatcurve_fts_query *query);
bool fts_flatcurve_xapian_run_query(struct flatcurve_fts_backend *backend,
				    struct flatcurve_fts_query *query,
				    struct fts_result *r);
void fts_flatcurve_xapian_destroy_query(struct flatcurve_fts_query *query);
bool fts_flatcurve_xapian_delete_index(struct flatcurve_fts_backend *backend);

/* if query absent, all documents are matched */
struct fts_flatcurve_xapian_uid_iterate_context
*fts_flatcurve_xapian_uid_iter_init(struct flatcurve_fts_backend *backend,
				    struct flatcurve_fts_query *query);
uint32_t fts_flatcurve_xapian_uid_iter_next(
	struct fts_flatcurve_xapian_uid_iterate_context *ctx);
void fts_flatcurve_xapian_uid_iter_deinit(
	struct fts_flatcurve_xapian_uid_iterate_context **ctx);

#endif
