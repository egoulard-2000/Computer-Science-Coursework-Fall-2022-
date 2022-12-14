%{
    Emile Goulard
    uID: u1244855
    CS3200 - Assignment 7

    Summary:
        This code randomly distributes 250 points inside the circle defined
        by 'circle-2douter.txt' from Question 2. It will then generate the
        triangulated mesh using those random points.

%}
hold all;
format long
fid = fopen('circle-2douter.txt', 'rt');
c = textscan(fid, '%f%f');
fclose(fid);

circlePoints = cell2mat(c);

theta = 0:pi/50:2*pi;
circleX = circlePoints(:, 1);
circleY = circlePoints(:, 2);
plot(circleX, circleY);

radius = 1;
centerX = 0;
centerY = 0;

% Plot within inside of circle plotted
t = 2 * pi * rand(250,1);
r = radius * sqrt(rand(250,1));
x = centerX + r.*cos(t);
y = centerY + r.*sin(t);
DT = delaunay(x,y);
triplot(DT,x,y);