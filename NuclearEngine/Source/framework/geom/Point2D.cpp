#include "Point2D.h"

ne_geom::point2D::point2D(double x, double y):
	x(x), y(y)
{}

ne_geom::point2D::point2D(const point2D & point):
	x(point.x), y(point.y)
{}

bool ne_geom::point2D::operator==(const point2D & point) const
{
	return (x == point.x && y == point.y);
}

bool ne_geom::point2D::operator!=(const point2D& point) const
{
	return !(*this == point);
}

ne_geom::point2D ne_geom::point2D::offset(const point2D& point) const
{
	return point2D(x - point.x, y - point.y);
}
