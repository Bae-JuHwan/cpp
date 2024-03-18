//-----------------------------------------------------------------------------
// save.cpp - �� �б� ���� �ҽ��� ������ �� �ִ� �Լ��� �����Ѵ�
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
	std::ofstream out{ "2023 2�б� C++ ��910 ��78 ��������.txt" , std::ios::app };

	auto now = std::chrono::system_clock::now();			  //���� �ð��� ������
	auto utc = std::chrono::system_clock::to_time_t(now);  //UTC�� ��ȯ
	auto lt = std::localtime(&utc);						  //�����ð����� ��ȯ
	auto old = out.imbue(std::locale("ko_KR"));			  //��½�Ʈ�� ��������

	out << '\n' << '\n';
	out << "===================================================" << '\n';
	out << "������ �ð�: " << std::put_time(lt, "%x %A %X") << '\n';
	out << "===================================================" << '\n';
	out << '\n';
	out.imbue(old);

	char c;
	in >> std::noskipws;
	while (in >> c)
		out << c;
}