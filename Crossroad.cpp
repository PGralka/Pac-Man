#include "Crossroad.h"

Crossroad::Crossroad() = default;

Crossroad::Crossroad(qreal x, qreal y, qreal w, qreal h) {
	setRect(x + 1, y + 1, w - 1, h - 1);
}

bool Crossroad::properContains(QRectF r) {
	if (boundingRect().top() <= r.top() &&
		boundingRect().bottom() >= r.bottom() &&
		boundingRect().left() <= r.left() &&
		boundingRect().right() >= r.right()) {
		return true;
	}
	return false;
}
