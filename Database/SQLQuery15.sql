USE Lebedeva_310;
/*��� ������ ������������ ���������� ���������� ���������, ��
������� ����������� ������*/
SELECT COUNT(route_id) AS '���������� ��������� ��� �����������', airline_id
	FROM Flights
	GROUP BY airline_id;

SELECT * FROM Flights;