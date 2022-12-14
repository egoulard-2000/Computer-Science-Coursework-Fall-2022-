%{
    Emile Goulard
    uID: u1244855
    CS3200 - Assignment 7

    Summary:
        This code reads the points defined
        by '2D-torso.txt' from Question 4 for Extra Credit. 
        It will then generate the triangulated mesh using those points.
        It will also generate a new mesh that 'attempts' to remove the
        triangles in the heart and some in the other points.

%}
function [] = A7_ExtraCredit()
    format long
    fid = fopen('2D-torso.txt', 'rt');
    c = textscan(fid, '%f%f%f');
    fclose(fid);

% Old Mesh
figure(1);
    hold on;
    title('Old Mesh');
    points = cell2mat(c);
    
    x = points(:, 2);
    y = points(:, 3);
    
    dt=delaunayTriangulation(x,y);
    
    list=dt.ConnectivityList;
    
    x=triangulation(list,dt.Points);
    
    triplot(x);

% New Mesh
figure(2);
    hold on;
    title('New Mesh');
    points = cell2mat(c);
    
    x = points(:, 2);
    y = points(:, 3);
    
    dt=delaunayTriangulation(x,y);
    
    list=dt.ConnectivityList;
   
    % Try and remove points by clamping values randomly in the connectivity
    % list
    a = 300;
    b = 500;
    for i=1:1196
        r = a + (b-a)*rand();
        if abs(list(i, 1)) < 100
            list(i, 1) = fix(r);
        end
    
        if abs(list(i, 2)) < 100
            list(i, 2) = fix(r);
        end
    
        if abs(list(i, 3)) < 100
            list(i, 3) = fix(r);
        end
    end
    
    x=triangulation(list,dt.Points);
    
    triplot(x);
end