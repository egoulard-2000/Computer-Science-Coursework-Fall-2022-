%{
    Emile Goulard
    uID: u1244855
    CS3200 - Assignment 7

    Summary:
        This code reads the points defined
        by 'circle2d.txt' from Question 3. It will then generate the
        triangulated mesh using those points.

%}
hold all;
format long
fid = fopen('circle2d.txt', 'rt');
c = textscan(fid, '%f%f');
fclose(fid);

circlePoints = cell2mat(c);

radius = 1;
theta = 0:pi/50:2*pi;
circleX = radius * cos(theta);
circleY = radius * sin(theta);
plot(circleX, circleY);

x = circlePoints(:, 1);
y = circlePoints(:, 2);
DT = delaunay(x,y);
triplot(DT,x,y);
