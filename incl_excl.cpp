#include "incl_excl.hpp"
#include <algorithm>

#define box_y2(box) (((box)->y) + ((box)->h))
#define box_x2(box) (((box)->x) + ((box)->w))

static bool is_covered (box* det, box* reg) {
return ((det->x >= reg->x) &&  box_x2(det) <= box_x2(reg) &&
        (det->y >= reg->y) &&  box_y2(det) <= box_y2(reg));
}

bool is_overlapped (box* det, box* reg) {
return (((std::min(box_x2(det), box_x2(reg)) - std::max(det->x, reg->x)) >=0) &&
        ((std::min(box_y2(det), box_y2(reg)) - std::max(det->y, reg->y)) >=0));
}

bool  is_excluded(box* det, box* reg, int num) {
    // check if box is entirely overlapped by the region
    if (is_covered(det, &reg[num])) return true;

    // check if all the regions were tested for a box
    if (num == -1) return false;

    else {
        // check if current region will split the box
        if (is_overlapped(det, &reg[num]))
        {
            // split the box
            box split;
            bool flag = true;
            if (det->x < reg[num].x) {
                split.x = det->x;
                split.y = det->y;
                split.w = reg[num].x - det->x;
                split.h = det->h;
                flag &= is_excluded(&split, reg, num-1);
                if (!flag) return false;
            }
            if (det->y < reg[num].y) {
                split.x = std::max(det->x, reg[num].x);
                split.y = det->y;
                split.w = box_x2(det) - std::max(det->x, reg[num].x);
                split.h = reg[num].y - det->y;
                flag &= is_excluded(&split, reg, num-1);
                if (!flag) return false;
            }
            if (box_x2(det) > box_x2(&reg[num])) {
                split.x = box_x2(&reg[num]);
                split.y = std::max(det->y, reg[num].y);
                split.w = box_x2(det) -  box_x2(&reg[num]);
                split.h = box_y2(det) - std::max(det->y,reg[num].y);
                flag &= is_excluded(&split, reg, num-1);
                if (!flag) return false;
            }
            if (box_y2(det) > box_y2(&reg[num])) {
                split.x = std::max(det->x,reg[num].x);
                split.y = box_y2(&reg[num]);
                split.w = std::min(det->w, reg[num].w);
                split.h = box_y2(det) - box_y2(&reg[num]);
                flag &= is_excluded(&split, reg, num-1);
                if (!flag) return false;
            }
            return flag;
        }
        return is_excluded(det, reg, num-1);
    }
}