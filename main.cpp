#include <iostream>
#include "Dungeoncrawler.h"
#include "List.h"
int main()
{
    std::vector<std::string> myMaps;
    myMaps.push_back({"##########"
                         "#O.......#"
                         "#...<....#"
                         "#..___...#"
                         "#..___...#"
                         "#!.......#"
                         "#######X##"
                         "#O.......#"
                         "#...?....#"
                         "##########"});

    myMaps.push_back({"##########"
                         "#O.......#"
                         "#...<....#"
                         "#..___...#"
                         "#..___...#"
                         "#........#"
                         "#######X##"
                         "#O.#.#...#"
                         "#...?...!#"
                         "##########"});

    myMaps.push_back({"##########"
                         "#O.......#"
                         "#...<...!#"
                         "#..___...#"
                         "#..___...#"
                         "#........#"
                         "#######X##"
                         "#O.......#"
                         "#...?...=#"
                         "##########"});

    DungeonCrawler D = DungeonCrawler(myMaps);
    D.start();


    return 0;
}
