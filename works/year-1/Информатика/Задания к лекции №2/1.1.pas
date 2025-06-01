program L2_1;
var
    a, b, o1, o2, o3, f: real;
begin
    write('Введите A, B: ');
    read(a, b);
    o1:= ln(a + b);
    o2:= sin(a) + sin(b);
    o3:= abs(o2);
    f = sqrt(o3) * o1;
    writeln('Ответ: f = ', f:4:2);
end.

program L2_2;
var
    a, b, f: real;
begin
    write('Введите A, B: ');
    read(a, b);
    f = (sqrt(abs(sin(a) + cos(b)))) * ln(a + b);
    writeln('Ответ: f = ', f:4:2);
end.