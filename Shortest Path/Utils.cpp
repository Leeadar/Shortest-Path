#include "Utils.h"


bool RELAX(float* d, int u, int v, float u_v_edge_weight)
{
	float d_v = d[v - 1];
	float d_u = d[u - 1];

	if (d_u == INFINITE)
	{
		return false;
	}
	else if (d_v == INFINITE)
	{
		d[v - 1] = d_u + u_v_edge_weight;
		return true;
	}
	else if (d_v > d_u + u_v_edge_weight)
	{
		d[v - 1] = d_u + u_v_edge_weight;
		return true;
	}
	return false;
}