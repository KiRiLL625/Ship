#include "raylib-cpp.hpp"

int main() {
    const int screenWidth = 900;
    const int screenHeight = 450;

    raylib::Window window(screenWidth, screenHeight, "Ship");

    // Координаты для корабля
    raylib::Rectangle shipBody(screenWidth/2 - 75 * 4, screenHeight/2, 150 * 4, 30 * 4);
    raylib::Rectangle shipMast(screenWidth/2 - 5 * 4, screenHeight/2 - 50 * 4, 10, 50 * 4);

    // Уменьшаем размеры парусов и перемещаем их, чтобы они висели на мачте
    raylib::Rectangle shipSailTop(screenWidth/2 - 5 * 4, screenHeight/2 - 50 * 4, 30 * 4, 5 * 4);
    raylib::Rectangle shipSailMiddle(screenWidth/2 - 5 * 4, screenHeight/2 - 45 * 4, 30 * 4, 5 * 4);
    raylib::Rectangle shipSailBottom(screenWidth/2 - 5 * 4, screenHeight/2 - 40 * 4, 30 * 4, 5 * 4);

    // Координаты для треугольников слева и справа от корабля
    raylib::Vector2 leftTriangle[3] = {
        {screenWidth/2 - 75 * 4, screenHeight/2 + 30 * 4},
        {screenWidth/2 - 75 * 4, screenHeight/2},
        {screenWidth/2 - 75 * 4 - 70, screenHeight/2}
    };
    raylib::Vector2 rightTriangle[3] = {
        {screenWidth/2 - 75 * 4 + 150 * 4, screenHeight/2 + 30 * 4},
        {screenWidth/2 - 75 * 4 + 150 * 4 + 70, screenHeight/2},
        {screenWidth/2 - 75 * 4 + 150 * 4, screenHeight/2}
    };

    // Координаты для пушек противовоздушной обороны
    raylib::Rectangle airDefenseGun1(screenWidth/2 - 75 * 4, screenHeight/2 - 10 * 4, 20 * 4, 10 * 4);
    raylib::Rectangle airDefenseGun2(screenWidth/2 + 55 * 4, screenHeight/2 - 10 * 4, 20 * 4, 10 * 4);

    // Координаты для дул пушек противовоздушной обороны
    raylib::Vector2 airDefenseGunBarrel1Start(screenWidth/2 - 75 * 4, screenHeight/2 - 10 * 4);
    raylib::Vector2 airDefenseGunBarrel1End(screenWidth/2 - 75 * 4 - 10 * 4, screenHeight/2 - 10 * 4 - 10 * 4);

    raylib::Vector2 airDefenseGunBarrel2Start(screenWidth/2 + 55 * 4 + 20 * 4, screenHeight/2 - 10 * 4);
    raylib::Vector2 airDefenseGunBarrel2End(screenWidth/2 + 55 * 4 + 20 * 4 + 10 * 4, screenHeight/2 - 10 * 4 - 10 * 4);

    // Толщина дул пушек
    int barrelThickness = 8;

    window.SetTargetFPS(60);

    while (!window.ShouldClose()) {
        BeginDrawing();

        ClearBackground(LIGHTGRAY);

        // Рисуем корабль
        shipBody.Draw(DARKGRAY); // Тело корабля
        DrawTriangle(leftTriangle[0], leftTriangle[1], leftTriangle[2], DARKGRAY); // Треугольник слева от корабля
        DrawTriangle(rightTriangle[0], rightTriangle[1], rightTriangle[2], DARKGRAY); // Треугольник справа от корабля
        shipMast.Draw(BROWN); // Мачта
        shipSailTop.Draw(WHITE); // Верхний парус
        shipSailMiddle.Draw(SKYBLUE); // Средний парус
        shipSailBottom.Draw(RED); // Нижний парус

        // Рисуем пушки противовоздушной обороны
        airDefenseGun1.Draw(DARKGRAY);
        airDefenseGun2.Draw(DARKGRAY);

        // Рисуем дула пушек противовоздушной обороны
        DrawLineEx(airDefenseGunBarrel1Start, airDefenseGunBarrel1End, barrelThickness, DARKGRAY);
        DrawLineEx(airDefenseGunBarrel2Start, airDefenseGunBarrel2End, barrelThickness, DARKGRAY);

        // Написать на борту корабля
        DrawText("Z", screenWidth/2 - 75 * 4 + 50, screenHeight/2 + 50, 40, ORANGE); // Изменен размер и положение текста
        DrawText("O", screenWidth/2, screenHeight/2 + 50, 40, ORANGE); // Изменен размер и положение текста
        DrawText("V", screenWidth/2 + 75 * 4 - 50, screenHeight/2 + 50, 40, ORANGE); // Изменен размер и положение текста

        EndDrawing();
    }

    return 0;
}