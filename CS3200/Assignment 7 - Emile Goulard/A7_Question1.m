%{
    Emile Goulard
    uID: u1244855
    CS3200 - Assignment 7

    Summary:
        This code will recursively create a circular mesh using the divide
        and conquer algorithm. 

%}
function [] = main()
    hold all;
    clc;
    clear;
    close all;

% ---- Circle Data
    radius = 2;
    theta = 0:pi/50:2*pi;
    circleX = radius * cos(theta);
    circleY = radius * sin(theta);

% --- Square Data
    width = radius * 2;
    height = radius * 2;

    PointsInX = 3;
    PointsInY = 3;

    delta_x = width / (PointsInX - 1);
    delta_y = height / (PointsInY - 1);

    plot(circleX, circleY);
    
% ---- Define point data
    points = zeros(2, PointsInX * PointsInY);
    
    % Calculate the points in the square
    index = 0;
    for i=1:PointsInY
        y = (i - 1) * delta_y;
        for j=1:PointsInX
            x = (j - 1) * delta_x;
            index = index + 1;

            points(1, index) = x;
            points(2, index) = y;
        end
    end
    
    recursionLevel = 0;
    square = [[0,0]; [0,2]; [2,0]; [2,2]];
    recurse(square, PointsInX, PointsInY, recursionLevel);

% ---- Define mesh data
    numOfTriangles = zeros(3, 2 * (PointsInX-1) * (PointsInY-1));
    
    index = 0;
    for i=1:PointsInY-1
        
        for j=1:PointsInX-1
            squareP1 = j + (PointsInX * (i-1));
            squareP2 = squareP1 + 1;
            squareP3 = squareP2 + PointsInX;
            squareP4 = squareP1 + PointsInX;
            index = index + 1;
            numOfTriangles(:, index) = [squareP1, squareP3, squareP4];
       
            index = index + 1;
            numOfTriangles(:, index) = [squareP1, squareP2, squareP3];
        end
    end

end

function [] = recurse(square, PointsInX, PointsInY, depth)
    hold all;
    
    persistent totalPoints
    if isempty(totalPoints)
        totalPoints = zeros(2, 33*33);
    end

    persistent totalPointsIndex
    if isempty(totalPointsIndex)
        totalPointsIndex = 0;
    end

    if depth ~= 6
        radius = 2;

        minArea = 0.015625;

        testPoint1 = square(1,1)^2 + square(1,2)^2 - radius^2;
        testPoint2 = square(2,1)^2 + square(2,2)^2 - radius^2;
        testPoint3 = square(3,1)^2 + square(3,2)^2 - radius^2;
        testPoint4 = square(4,1)^2 + square(4,2)^2 - radius^2;
        
        % if all points are inside, keep square
        if testPoint1 < 0 && testPoint2 < 0 && testPoint3 < 0 && testPoint4 < 0
            for i=1:4
                totalPointsIndex = totalPointsIndex + 1;
                totalPoints(1, totalPointsIndex) = square(i,1);
                totalPoints(2, totalPointsIndex) = square(i,2);
            end
            return;
        end
    
        % if all points are outside, throw away square
        if testPoint1 > 0 && testPoint2 > 0 && testPoint3 > 0 && testPoint4 > 0
            return;
        end
        
        % If partially in square, recurse
        distance = sqrt((square(4,1)-square(1,1))^2 + (square(4,2)-square(1,2))^2);
        if distance > radius
            currentWidth = square(4,1)-square(1,1);
            currentHeight = square(4,2)-square(1,2);
            currentArea = currentWidth * currentHeight;
            
            if currentArea > minArea
                
                PointsInX = PointsInX * 2 - 1;
                PointsInY = PointsInY * 2 - 1;
    
                width = currentWidth;
                height = currentHeight;
                delta_x = width / (PointsInX - 1);
                delta_y = height / (PointsInY - 1);
               
                % ---- Define point data
                points = zeros(2, PointsInX * PointsInY);
                % Calculate the points in the square
                index = 0;
                for i=1:PointsInY
                    y = (i - 1) * delta_y;
                    for j=1:PointsInX
                        x = (j - 1) * delta_x;
                        index = index + 1;
            
                        points(1, index) = x;
                        points(2, index) = y;
                    end
                end
    
                % ---- Define mesh data
                numOfTriangles = zeros(3, 2 * (PointsInX-1) * (PointsInY-1));
                
                index = 0;
                for i=1:PointsInY-1
                    for j=1:PointsInX-1
                        squareP1 = j + (PointsInX * (i-1));
                        squareP2 = squareP1 + 1;
                        squareP3 = squareP2 + PointsInX;
                        squareP4 = squareP1 + PointsInX;
                        index = index + 1;
                        numOfTriangles(:, index) = [squareP1, squareP3, squareP4];
                   
                        index = index + 1;
                        numOfTriangles(:, index) = [squareP1, squareP2, squareP3];
                    end
                end

                newSquare = [[square(1,1)/2, square(1,2)/2]; [square(2,1)/2, square(2,2)/2]; [square(3,1)/2, square(3,2)/2]; [square(4,1)/2, square(4,2)/2]];
                recurse(newSquare, PointsInX, PointsInY, depth);

                %Plot mesh
                patch('faces', numOfTriangles','vertices', points', 'facecolor', 'c', 'edgecolor', 'k');
                triplot(points(1, :), points(2, :));
            end

        end

    end

    return;
    
end