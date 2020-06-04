#include <vector>

using std::vector;

class ModelGame
{
	private:
		const int width;
		const int height;
		vector<vector<bool>> Board;
		int modulus(int a, int b);

	public:
		ModelGame(const int w = 400, const int h = 400);
		ModelGame();
		bool check(int x, int y);
		void update();
		vector<vector<int>> blackCells();
		void setBlack(int row, int column);
};
