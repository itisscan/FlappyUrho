#pragma once
#include "Global.h"

// Этот компонент прикрепляется к ноде с НЛО.
class UfoLogic : public LogicComponent
{
    URHO3D_OBJECT(UfoLogic, LogicComponent);

public:
    UfoLogic(Context* context);
    static void RegisterObject(Context* context);
    void OnNodeSet(Node* node);
    void Update(float timeStep);
    void Reset();
    void HandleCollisionStart(StringHash eventType, VariantMap& eventData);
    void HandleCollisionEnd(StringHash eventType, VariantMap& eventData);

private:
	void JumpUfo();

private:
    // Скорость НЛО по вертикали.
    // По горизонтали НЛО всегда находится в начале координат, но может двигаться по оси Y.
    // Положительная скорость - НЛО движется вверх, отрицательная - вниз.
    float verticalSpeed_;

    // Задержка до следующего прыжка, чтобы игрок не мог прыгать слишком часто.
    float jumpDelay_;

	// Для кешинга. Что бы не вызывать каждый кадр GLOBAL->IsTouchEnabled();
	bool touchEnabled_;		
};
