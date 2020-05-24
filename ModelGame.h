class ModelGame
{
	private:
		int width;
		int height;
		vector<vector<int>> Board;
		int check(int x, int y);

	public:
		ModelGame(const int width = 400, const int height = 400);
		vector<vector<int>> update();
}