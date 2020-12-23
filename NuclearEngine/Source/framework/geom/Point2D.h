#ifndef NE_POINT_2D_H
#define NE_POINT_2D_H
#pragma once

// Define Namespace
namespace ne_geom
{
	struct point2D
	{
	public:
		double x;
		double y;

		point2D(double x = 0, double y = 0);
		point2D(const point2D& point);

		bool operator==(const point2D& point) const;
		bool operator!=(const point2D& point) const;
		point2D offset(const point2D& point) const;
	};
} // namespace ne_geom

#endif // !NE_POINT_2D_H
