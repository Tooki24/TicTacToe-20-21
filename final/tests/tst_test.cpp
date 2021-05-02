#include <QtTest>
#include "../sourceCode/grid.h"
#include "../sourceCode/player.h"

// add necessary includes here

class test : public QObject
{
    Q_OBJECT

public:
    test();
    ~test();

private slots:
    void test_checkCoord();
    void test_checkWin();

};

test::test()
{

}

test::~test()
{

}

void test::test_checkCoord()
{
    Player player("Mélina",HUMAN, CROSSES);
    Grid grid(3);
    QCOMPARE(grid.checkCoord("A2"),true);
}


void test::test_checkWin(){
    Player player("Mélina",HUMAN, CROSSES);
    Grid grid(3);
    grid.placePion("A0",player.getItsState());
    grid.placePion("A1",player.getItsState());
    grid.placePion("A2",player.getItsState());
    QCOMPARE(grid.checkWin("A2",player),true);

}

QTEST_APPLESS_MAIN(test)

#include "tst_test.moc"
