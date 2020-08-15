#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<map>
#include<list>
#include<queue>

using namespace std;

typedef map<string, list<string>> mapList;

std::map<string, string> flip_map(const mapList &songGenres)
{
	std::map<string, string> dst;
	for (auto& genreSong: songGenres)
	{
		string genre = genreSong.first;
		list<string> songs = genreSong.second;
		/*for (auto& song : songs)
		{
			dst.insert(song, genre);
		}*/
		for_each(songs.begin(), songs.end(), [&](string song) {
			dst.insert(make_pair(song, genre)); 
		});
	}
	return dst;
}

int main()
{
	mapList userSongs = { {"David", {"song1", "song2", "song3", "song4", "song8" }}, {"Emma", {"song5", "song6", "song7" }}};
	mapList songGenres = {
		{"Rock",{"song1", "song3"} },
		{"Dubstep", {"song7"} },
		{"Techno", {"song2", "song4" } },
		{"Pop", {"song5", "song6"}},
		{"Jazz" , {"song8", "song9" }} };

	map<string, string> genreSongs = flip_map(songGenres);

	map<string, map<string, int>> favGenreMap;
	map<string, list<string>> favGenreList;

	for (auto& user: userSongs)
	{
		string userName = user.first;
		list<string> userSongs = user.second;
		map<string, int> genreToCount;
		list<string> maxGenre;
		int maximum = 0;
		for (auto& song : userSongs)
		{
			string genre = genreSongs[song];
			++genreToCount[genre];
			if (genreToCount[genre] >= maximum)
			{
				maximum = genreToCount[genre];
			}
		}

		for (auto it = genreToCount.begin(); it != genreToCount.end(); ++it)
		{
			if (it->second == maximum)
			{
				maxGenre.push_back(it->first);
			}
		}
		favGenreList.insert(make_pair(userName, maxGenre));
	}
}