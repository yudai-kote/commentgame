#pragma once
#include "../CharacterBase/CharacterBase.h"
#include "../Share/Property/PropertySystem.h"

class Player : public CharacterBase
{
public:
	Player(Vec2f _pos, Vec2f _size);
	~Player();
	void draw() override;
	void update() override;

	void setPos(Vec2f _pos);
	Vec2f getPos();
	void setSize(Vec2f _size);
	Vec2f getSize();
	WritableP<bool> is_dead;

	enum CharaState {
		STOP,
		WALK,

		BOMB_PICK_UP,
		BOMB_HAVE,
		//BOMB_HAVE_MOVE,
		BOMB_THROW,

		BOW_HAVE,
		//BOW_HAVE_MOVE,
		BOW_SHOT,

		DEAD,

		CLEAR,

	};

private: // キャラの状態変更
	CharaState charastate = STOP;
	void charastateUpdate();

	void move();
private: // 物
	bool is_pick_up = false;
	bool is_have = false;
	bool is_throw = false;
	void itemThrowMotion();
	int item_count = 0;

public: // ステージクリア
	bool getStageClear() { return is_stageclear; }
private:
	bool is_stageclear = false;

public: // 弓
	bool getIsBowHave() { return is_bow_have; }
	bool getIsBowShot() { return is_bow_shot; }

private:

	bool is_bow_have = false;
	bool is_bow_shot = false;

private: // 死亡
	bool is_dead_ = false;
	void dead();
	std::set<int> size_change_timing;
	int default_size = size.x();
	void sizeReset();
	void deadMotion();
	int dead_count;
	void sizeChange();

private: // 画像読み込み
	void resourceRoad();

private: // アニメーション

	std::unordered_map<std::string, int> animation_name;
	int getAnimationTime(const std::string name_);

	std::set<int> now_animation;
	void animationChange();

	void animationSetup();
	void animationUpdate();
	void animationDraw();



};

