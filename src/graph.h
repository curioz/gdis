/*
Copyright (C) 2003 by Sean David Fleming

sean@ivec.org

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

The GNU GPL can also be found at http://www.gnu.org
*/

typedef enum {
        GRAPH_REGULAR=0,/*previous plain graph*/
        GRAPH_FREQUENCY,/*impulse graph for frequency*/
        GRAPH_BAND,/*kpoints/state energy graph */
	GRAPH_DOS,/*interleave e,dos plot*/
        GRAPH_BANDOS,/*dual BAND & DOS graph*/
	GRAPH_USPEX,/*point graph with selectable*/
	GRAPH_USPEX_BEST,/*linepoint graph with selectable*/
	GRAPH_USPEX_COMP,/*composition vs energy, point with selectable*/
	GRAPH_USPEX_2D,/*2D point graph with selectable*/
} graph_type;
/*******************/
/* data structures */
/*******************/
struct graph_pak
{
	gint grafted;
	gchar *treename;
	gint treenumber;
	/* graph generation parameters */
	gdouble wavelength;
	/* flags */
	gint xlabel;
	gint ylabel;
	graph_type type;
	/* graph layout */
	gint xticks;
	gint yticks;
	gdouble xmin;
	gdouble xmax;
	gdouble ymin;
	gdouble ymax;
	/* NB: all sets are required to be <= size */
	gint size;
	GSList *set_list;/*in case of 1D graph, set_list={x[,tag]} for 2D set_list={x,y[,tag]}*/
	/* peak selection */
	gint select;
	gdouble select_2;/*uspex peak selections require two index*/
	gchar *select_label;
};
gpointer graph_new(const gchar *, struct model_pak *);
void graph_free_list(struct model_pak *);
void graph_free(gpointer, struct model_pak *);
void graph_add_data(gint, gdouble *, gdouble, gdouble, gpointer);
void graph_add_borned_data(gint size,gdouble *x,gdouble x_min,gdouble x_max,gdouble y_min,gdouble y_max,gint type,gpointer data);
void graph_frequency_select(gint x, gint y, struct model_pak *model);
void graph_uspex_select(gint x, gint y, struct model_pak *model);
void graph_uspex_2d_select(gint x, gint y, struct model_pak *model);
void graph_set_grafted(gint, gpointer);
void graph_set_xticks(gint, gint, gpointer);
void graph_set_yticks(gint, gint, gpointer);
void graph_set_wavelength(gdouble, gpointer);
void graph_set_select(gdouble, gchar *, gpointer);
void graph_write(gchar *, gpointer);
void graph_read(gchar *);
gchar *graph_treename(gpointer);

gint graph_grafted(gpointer);
gint graph_xlabel(gpointer);
gint graph_ylabel(gpointer);
gdouble graph_xmin(gpointer);
gdouble graph_xmax(gpointer);
gdouble graph_ymin(gpointer);
gdouble graph_ymax(gpointer);
gdouble graph_wavelength(gpointer);

/* TODO - relocate */
gint anim_next_frame(struct model_pak *);

