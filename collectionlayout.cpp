#include "collectionlayout.h"

void CollectionLayout::addElement(OrderCell *element, OrderModel model)
{




    int index = items->size();
    items->append(index);
    element->model = model;
    if (index == 0) {
        element->setIndex(0);
    } else {
        element->setIndex(index - 1);
    }




    QPair<int, int> pairLocation;

    if (items->size() - 1 == 0) {
        pairLocation.first = 0;
        pairLocation.second = 0;
    } else if (cellsLocation->size() % 4 == 0) {
        int endIndex = cellsLocation->last().second + 1;
        pairLocation.second = endIndex;
        pairLocation.first = 0;
    } else {
        int endIndex = cellsLocation->last().second;
        int endHorizontal = cellsLocation->last().first + 1;

        pairLocation.second = endIndex;
        pairLocation.first = endHorizontal;
    }

    cellsLocation->append(pairLocation);

    QPair<int, int> cellLoc = cellsLocation->last();
    addWidget(element, cellLoc.second, cellLoc.first);


    OrderCell *cell = new  OrderCell();




}

void CollectionLayout::removeAll()
{
    OrderCell *cell = new OrderCell();
    for (int i = 0; i < items->size(); i++) {
        removeWidget(cell);

    }
}

CollectionLayout::CollectionLayout()
{


    setAlignment(Qt::AlignTop);
    setSpacing(45);
    setMargin(50);
}
