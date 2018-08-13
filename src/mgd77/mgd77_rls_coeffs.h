/* -------------------------------------------------------------------
 *      See LICENSE.TXT file for copying and redistribution conditions.
 *
 *    Copyright (c) 2004-2018 by P. Wessel and M. T. Chandler
 *	File:	mgd77_rls_coeffs.c
 *
 *	Tables consisting of regression statistics for (in this order):
 *		Ship bathymetry vs S2004 predicted bathymetry (slope and correlation)
 *		Ship gravity vs Sandwell & Smith version 15 altimetry derived gravity (slope, intercept, correlation)
 *		Ship gravity vs recomputed ship gravity (slope, intercept, rms)
 *		Ship residual magnetics vs recomputed ship residual magnetics (slope, intercept, rms)
 *
 *	Each table consists of the regression statistic along with the portion 
 *	of data less than or equal to that statistic (i.e., 1.0936% of cruises have
 *	bathymetry/S2004 regression slope <= 0.699999) 
 *
 *	This information is derived directly from regression statistics for all
 *  marine geophysical trackline data available as of June 2007.
 *
 *	These tables enable mgd77sniffer to set percentages of the archive as
 *	questionable rather than specifying hard numbers as limits, useful for
 *	testing purposes.
 *
 *	Authors:
 *		Michael Chandler and Paul Wessel
 *		School of Ocean and Earth Science and Technology
 *		University of Hawaii
 * 
 *	Date:	June 2007
 * 
 * ------------------------------------------------------------------*/

/*!
 * \file mgd77_rls_coeffs.h
 * \brief  
 */

#define RLS_N_DEPTH         4490
#define RLS_N_DEPTH_ROWS    39
#define RLS_N_FAA           1614
#define RLS_N_FAA_ROWS      43
#define RLS_N_RECOMPUTE_FAA 663
#define RLS_N_NEWFAA_ROWS   35
#define RLS_N_RECOMPUTE_MAG 2180
#define RLS_N_NEWMAG_ROWS   40

struct RLS {
	double cd;
	double m;
	double b;
	double rms;
	double r;
};

/* Regression tables for ship vs vs altimetry derived BATHYMETRY */
static struct RLS depth_v_grid[RLS_N_DEPTH_ROWS] = {
		/* cumulative dist,	slope,	icept, rms, corr */
		{0.010000,      0.426536,               0.000000,               3.041890,               0.192934},
		{0.020000,      0.624991,               0.000000,               35.355300,              0.358405},
		{0.030000,      0.865582,               0.000000,               39.528500,              0.503722},
		{0.040000,      0.933333,               0.000000,               44.095900,              0.620174},
		{0.050000,      0.961538,               0.000000,               48.653400,              0.714286},
		{0.060000,      0.964286,               0.000000,               51.433000,              0.788969},
		{0.070000,      0.965689,               0.000000,               54.609800,              0.830803},
		{0.080000,      0.965689,               0.000000,               57.566900,              0.858282},
		{0.090000,      0.965689,               0.000000,               59.941300,              0.881517},
		{0.100000,      0.965689,               0.000000,               62.158200,              0.899600},
		{0.110000,      0.995777,               0.000000,               64.151300,              0.912160},
		{0.120000,      0.995777,               0.000000,               65.769200,              0.919097},
		{0.130000,      0.995777,               0.000000,               67.612300,              0.928296},
		{0.140000,      0.995777,               0.000000,               69.234300,              0.935817},
		{0.150000,      0.995777,               0.000000,               70.415400,              0.942369},
		{0.200000,      0.995777,               0.000000,               74.781600,              0.963010},
		{0.250000,      0.995777,               0.000000,               78.801500,              0.972603},
		{0.400000,      1.000000,               0.000000,               121.408000,             0.987684},
		{0.450000,      1.000000,               0.000000,               128.279000,             0.990000},
		{0.500000,      1.000000,               0.000000,               137.888000,             0.991904},
		{0.550000,      1.000000,               0.000000,               144.519000,             0.993308},
		{0.650000,      1.000000,               0.000000,               156.457000,             0.995433},
		{0.750000,      1.000000,               0.000000,               199.516000,             0.996888},
		{0.800000,      1.003500,               0.000000,               216.460000,             0.997577},
		{0.850000,      1.003500,               0.000000,               238.170000,             0.998204},
		{0.860000,      1.003500,               0.000000,               249.387000,             0.998305},
		{0.870000,      1.003500,               0.000000,               259.697000,             0.998393},
		{0.880000,      1.003500,               0.000000,               265.709000,             0.998460},
		{0.890000,      1.003500,               0.000000,               273.855000,             0.998534},
		{0.900000,      1.003500,               0.000000,               282.398000,             0.998636},
		{0.910000,      1.003500,               0.000000,               288.066000,             0.998701},
		{0.920000,      1.031160,               0.000000,               296.774000,             0.998785},
		{0.930000,      1.031250,               0.000000,               314.708000,             0.998867},
		{0.950000,      1.032260,               0.000000,               353.543000,             0.999016},
		{0.960000,      1.034090,               0.000000,               379.024000,             0.999094},
		{0.970000,      1.038430,               0.000000,               429.410000,             0.999204},
		{0.980000,      1.074070,               0.000000,               506.973000,             0.999290},
		{0.990000,      1.230100,               0.000000,               858.693000,             0.999511},
		{1.000000,      62.957100,              0.000000,               5486.920000,            1.000000}
};

/* Regression tables for ship vs vs altimetry derived GRAVITY */
static struct RLS faa_v_grid[RLS_N_FAA_ROWS] = {
		/* cumulative dist,	slope,	icept, rms, corr */
		{0.010410,      -0.339662,              -39.221800,             5.392740,               0.190317},
		{0.020208,      0.058180,               -29.904000,             6.434770,               0.376194},
		{0.030006,      0.301339,               -22.819100,             7.132470,               0.534229},
		{0.040416,      0.551985,               -19.774000,             7.336170,               0.642279},
		{0.050214,      0.711736,               -17.325600,             7.571770,               0.716020},
		{0.060012,      0.771229,               -15.858000,             7.730580,               0.759717},
		{0.070423,      0.813963,               -14.503700,             7.833490,               0.796643},
		{0.080220,      0.838321,               -13.582500,             7.938120,               0.816988},
		{0.090018,      0.861850,               -12.480200,             8.012490,               0.831886},
		{0.100429,      0.874043,               -11.456000,             8.127710,               0.847523},
		{0.110227,      0.887840,               -10.602800,             8.241630,               0.857062},
		{0.120024,      0.896483,               -9.938870,              8.329170,               0.873471},
		{0.130435,      0.903083,               -9.435150,              8.413380,               0.882822},
		{0.140233,      0.909038,               -8.963870,              8.497910,               0.890085},
		{0.150031,      0.913863,               -8.433610,              8.637670,               0.895922},
		{0.200245,      0.936610,               -6.546920,              9.592390,               0.918321},
		{0.250459,      0.948252,               -5.429020,              10.606600,              0.932725},
		{0.300061,      0.957549,               -4.268260,              11.418800,              0.946002},
		{0.350276,      0.964880,               -3.380720,              11.988900,              0.955087},
		{0.400490,      0.972264,               -2.551830,              12.584200,              0.960967},
		{0.450092,      0.977933,               -1.805280,              13.310300,              0.966880},
		{0.500306,      0.983826,               -1.053690,              14.147100,              0.971497},
		{0.550521,      0.989098,               -0.330545,              15.038700,              0.974569},
		{0.600122,      0.993361,               0.552609,               15.867800,              0.977042},
		{0.650337,      0.998942,               1.396710,               16.999300,              0.979561},
		{0.700551,      1.003850,               2.309060,               18.200300,              0.982186},
		{0.750153,      1.009410,               3.329250,               19.591200,              0.985054},
		{0.800367,      1.016120,               4.529540,               21.308300,              0.988102},
		{0.850582,      1.024410,               6.298160,               24.376100,              0.990375},
		{0.860380,      1.026680,               6.854670,               25.041600,              0.991115},
		{0.870178,      1.029760,               7.231360,               25.495100,              0.991543},
		{0.880588,      1.033400,               7.629610,               26.578800,              0.992192},
		{0.890386,      1.035710,               8.312480,               27.634500,              0.992754},
		{0.900184,      1.038940,               8.771460,               28.499500,              0.993080},
		{0.910594,      1.041840,               9.565810,               29.470300,              0.993478},
		{0.920392,      1.045630,               10.505300,              31.261000,              0.993822},
		{0.930190,      1.049160,               12.065900,              33.117600,              0.994149},
		{0.950398,      1.066730,               14.429000,              37.161300,              0.995223},
		{0.960196,      1.081270,               16.185200,              46.701800,              0.995552},
		{0.980404,      1.119990,               25.324700,              76.863200,              0.996852},
		{0.990202,      1.594060,               50.781200,              311.906000,             0.997817},
		{1.000000,      10.537400,              838.219000,             984.001000,             0.998893}
};


/* Regression tables for reported vs recomputed GRAVITY */
static struct RLS faa_v_newfaa[RLS_N_NEWFAA_ROWS] = {
		/* cumulative dist,	slope,	icept, rms, corr */
		{0.010558,      0.076098,               -51.798854,             0.000000,               0.291061},
		{0.021116,      0.098071,               -36.529633,             0.000000,               0.375102},
		{0.030166,      0.138269,               -27.612108,             0.000000,               0.417195},
		{0.040724,      0.211522,               -22.796463,             0.000000,               0.498237},
		{0.060332,      0.277396,               -16.751005,             0.000000,               0.539218},
		{0.070890,      0.289304,               -15.659775,             0.000000,               0.564499},
		{0.090498,      0.322859,               -15.000000,             0.000000,               0.606345},
		{0.101056,      0.347891,               -15.000000,             0.000000,               0.616623},
		{0.110106,      0.355844,               -15.000000,             0.000000,               0.645580},
		{0.120664,      0.391676,               -15.000000,             0.000000,               0.667281},
		{0.140271,      0.447039,               -14.384222,             0.000000,               0.711831},
		{0.150830,      0.466474,               -14.031019,             0.000000,               0.723223},
		{0.200603,      0.597242,               -10.448459,             0.000000,               0.812204},
		{0.250377,      0.759884,               -7.704270,              0.000000,               0.878037},
		{0.300151,      0.838274,               -2.741194,              0.000000,               0.927644},
		{0.450980,      0.998489,               0.000000,               3.830654,               0.998723},
		{0.500754,      1.000000,               0.000000,               10.000000,              0.999370},
		{0.550528,      1.000000,               0.000000,               14.801124,              1.000000},
		{0.600302,      1.000000,               0.000000,               15.351336,              1.000000},
		{0.650075,      1.000000,               0.000000,               23.839219,              1.000000},
		{0.751131,      1.000000,               0.459695,               41.009019,              1.000000},
		{0.800905,      1.000000,               2.500000,               45.327865,              1.000000},
		{0.850679,      1.000000,               4.128202,               49.832136,              1.000000},
		{0.870287,      1.000000,               5.175149,               51.143181,              1.000000},
		{0.880845,      1.000000,               6.336073,               52.015053,              1.000000},
		{0.900452,      1.000000,               8.788721,               53.358449,              1.000000},
		{0.911011,      1.000000,               10.187081,              54.679741,              1.000000},
		{0.920060,      1.000000,               11.420808,              55.636912,              1.000000},
		{0.930618,      1.000000,               15.403046,              56.629489,              1.000000},
		{0.941176,      1.000000,               20.268192,              57.408023,              1.000000},
		{0.950226,      1.000000,               21.200144,              57.983154,              1.000000},
		{0.960784,      1.000835,               24.879612,              60.179833,              1.000000},
		{0.980392,      1.005947,               39.274516,              68.584005,              1.000000},
		{0.990950,      1.018246,               54.752397,              80.994288,              1.000000},
		{1.000000,      1.158792,               867.178156,             872.378573,             1.000000}
};

/* Regression tables for reported vs recomputed RESIDUAL MAGNETICS */
static struct RLS mag_v_newmag[RLS_N_NEWMAG_ROWS] = {
		/* cumulative dist,	slope,	icept, rms, corr */
		{0.010092,      0.101400,               -606.577982,            7.866601,               0.427481},
		{0.020183,      0.599294,               -520.143108,            10.000000,              0.600456},
		{0.030275,      0.737637,               -469.889635,            11.754390,              0.663064},
		{0.040367,      0.786904,               -420.304361,            15.092309,              0.711730},
		{0.050000,      0.821159,               -381.935686,            16.998632,              0.756631},
		{0.060092,      0.845379,               -349.099340,            18.451997,              0.790924},
		{0.070183,      0.864929,               -318.611931,            20.638483,              0.806299},
		{0.080275,      0.879594,               -292.060224,            23.061913,              0.817200},
		{0.090367,      0.891082,               -258.781069,            25.060773,              0.830688},
		{0.100000,      0.899080,               -235.918219,            26.827710,              0.843912},
		{0.110092,      0.907709,               -214.790241,            28.408927,              0.856998},
		{0.120183,      0.916495,               -202.519337,            29.592334,              0.866573},
		{0.130275,      0.923993,               -190.912578,            31.178406,              0.879597},
		{0.140367,      0.928937,               -182.496299,            32.687623,              0.884937},
		{0.150000,      0.932906,               -171.322405,            34.511955,              0.891162},
		{0.200000,      0.950803,               -131.506659,            40.906397,              0.917305},
		{0.250000,      0.962210,               -107.859894,            47.974445,              0.933306},
		{0.400000,      0.983677,               -47.685305,             69.852671,              0.968502},
		{0.450000,      0.988135,               -36.496956,             78.148568,              0.975656},
		{0.500000,      0.991864,               -27.009415,             87.548381,              0.980701},
		{0.550000,      0.995201,               -17.876120,             97.961465,              0.985089},
		{0.650000,      0.999499,               -0.892755,              127.821688,             0.991282},
		{0.750000,      1.003461,               22.811899,              160.941120,             0.995841},
		{0.800000,      1.007314,               38.457427,              185.472709,             0.997349},
		{0.850000,      1.013650,               56.088818,              217.292681,             0.998463},
		{0.860092,      1.015282,               60.361773,              227.680465,             0.998622},
		{0.870183,      1.016651,               64.535216,              245.021216,             0.998729},
		{0.880275,      1.018375,               70.000000,              252.669977,             0.998835},
		{0.890367,      1.020836,               76.011422,              274.419011,             0.998966},
		{0.900000,      1.023454,               82.921170,              296.579569,             0.999085},
		{0.910092,      1.027724,               94.755744,              320.032584,             0.999156},
		{0.920183,      1.031808,               108.800498,             341.530364,             0.999270},
		{0.930275,      1.036951,               127.176745,             361.819076,             0.999361},
		{0.940367,      1.041953,               141.993065,             389.280227,             0.999481},
		{0.950000,      1.052407,               159.398312,             416.352787,             0.999576},
		{0.960092,      1.067027,               173.000153,             447.684220,             0.999684},
		{0.970183,      1.078032,               204.228098,             499.865089,             0.999746},
		{0.980275,      1.107429,               235.000528,             551.486020,             0.999884},
		{0.990367,      1.181840,               298.227858,             642.360997,             1.000000},
		{1.000000,      5.123210,               2214.931273,            2213.744726,            1.000000}
};
