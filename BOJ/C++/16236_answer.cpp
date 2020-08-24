#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <functional>
using namespace std;

const int MAX = 20;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0 } };

typedef struct
{
	int time, y, x;
}pass;

bool operator<(const pass &p1, const pass &p2)
{
	if (p1.time > p2.time)
		return true;
	else if (p1.time == p2.time && p1.y > p2.y)
		return true;
	else if (p1.time == p2.time && p1.y == p2.y && p1.x > p2.x)
		return true;
	return false;
}

int arr[MAX][MAX];
bool visited[MAX][MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	pair<int, int> start;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			//상어의 위치
			if (arr[i][j] == 9)
			{
				start = { i, j };
				//0으로 초기화
				arr[i][j] = 0;
			}
		}

	queue<pair<pair<int, int>, int>> q;
	q.push({ { start }, 2 });
	//결과
	int duration = 0;
	//먹은 생선 마리수
	int cnt = 0;

	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int size = q.front().second;
		q.pop();

		//매번 visited 초기화 해줘야 함!
		memset(visited, false, sizeof(visited));
		//가는 경로 우선순위 위해
		priority_queue<pass> temp;
		temp.push({ 0, y, x });
		visited[y][x] = true;

		while (!temp.empty())
		{
			//같은 거리 내 모두 비교
			int iter = temp.size();
			//우선순위는 y가 작은순, y가 같다면 x가 작은순입니다.
			priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
			for (int j = 0; j < iter; j++)
			{
				int curY = temp.top().y;
				int curX = temp.top().x;
				int curTime = temp.top().time;
				temp.pop();

				for (int i = 0; i < 4; i++)
				{
					int nextY = curY + moveDir[i].y;
					int nextX = curX + moveDir[i].x;

					//범위 내에 있고
					if (0 <= nextY && nextY < N && 0 <= nextX && nextX < N)
						//방문하지 않았으며
						if (!visited[nextY][nextX])
						{
							//지나갈 수 있다면
							if (arr[nextY][nextX] <= size)
							{
								temp.push({ curTime + 1, nextY, nextX });
								visited[nextY][nextX] = true;
								//먹이 후보 중 하나
								if (1 <= arr[nextY][nextX] && arr[nextY][nextX] < size)
									pq.push({ { nextY, nextX }, curTime + 1 });
							}
						}
				}
			}

			//우선순위가 제일 높은 먹이를 먹는다
			if (!pq.empty())
			{
				cnt++;
				// 크기 커질 조건
				if (cnt == size)
				{
					q.push({ { pq.top().first }, size + 1 });
					cnt = 0;
				}
				else
					q.push({ {pq.top().first}, size });
				//초기화 해주고
				cout<<"x:"<<pq.top().first.first<<"y:"<<pq.top().first.second<<endl;
				arr[pq.top().first.first][pq.top().first.second] = 0;
				//시간을 더해준다
				cout<<pq.top().second<<endl;
				duration += pq.top().second;
				break;
			}
		}
	}

	cout << duration << "\n";
	return 0;
}
