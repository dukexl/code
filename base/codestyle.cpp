#include <iostream>

using namespace std;
// �ڴ���ö��ʱ�������Ƿ������ƿռ��У��Ա����ʹ������������Ʒ�������:
namespace EntityType {
	enum Enum {
		Ground = 0,
		Human,
		Aerial,
		Total
	};
}

void foo(EntityType::Enum entityType)
{
	if (entityType == EntityType::Ground) {
		/*code*/
	}
}

// enum class
enum class EntityType1 {
	Ground = 0,
	Human,
	Aerial,
	Total
};

void foo(EntityType1 entityType)
{
	if (entityType == EntityType1::Ground) {
		/*code*/
	}
}

int main() {

	return 0;
}