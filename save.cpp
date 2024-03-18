//-----------------------------------------------------------------------------
// save.cpp - 한 학기 강의 소스를 저장할 수 있는 함수를 정의한다
//
// 2023. 9. 6
//-----------------------------------------------------------------------------
#include <string>
#include <chrono>
#include <fstream>
#include <iomanip>

void save(const std::string& fileName)
{
	std::ifstream in{ fileName };
	std::ofstream out{ "2023 2학기 C++ 월910 수78 강의저장.txt" , std::ios::app };

	auto now = std::chrono::system_clock::now();			  //현재 시간을 가져옴
	auto utc = std::chrono::system_clock::to_time_t(now);  //UTC로 변환
	auto lt = std::localtime(&utc);						  //지역시간으로 변환
	auto old = out.imbue(std::locale("ko_KR"));			  //출력스트림 지역변경

	out << '\n' << '\n';
	out << "===================================================" << '\n';
	out << "저장한 시간: " << std::put_time(lt, "%x %A %X") << '\n';
	out << "===================================================" << '\n';
	out << '\n';
	out.imbue(old);

	char c;
	in >> std::noskipws;
	while (in >> c)
		out << c;
}