USE Lebedeva_310;
/*������� ��������� � ���������� �� ��������� � ��������
����������*/
 
DECLARE @route_id INT
EXEC insert_route  @route_id OUTPUT, '������������', '������'
PRINT @route_id;

SELECT * FROM Route;