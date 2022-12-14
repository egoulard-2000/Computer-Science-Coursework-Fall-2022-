%{
    Emile Goulard
    uID: u1244855
    CS3200 - Assignment 6

    Summary:
        This is meant to be ran for measuring times of the matrix classes
        provided for Question 1.

        - figureNum: determines which figure to run. 
        insert 1 to run Dot Matrix
        insert 2 to run Outer Matrix
        insert 3 to run Saxpy Matrix
        insert 4 to run Vector Matrix
        insert 5 to run Direct Matrix

%}
function [ ] = A6_Question1(figureNum)
    
    if figureNum == 1
        disp('---- Times for Matrix Dot ----');
        for MatSize = [128, 512, 1024, 4096]
            MatMatClass.MatMatDot(MatSize);
        end
    end

    if figureNum == 2
        disp('---- Times for Matrix Outer ----');
        for MatSize = [128, 512, 1024, 4096]
            MatMatClass.MatMatOuter(MatSize);
        end
    end

    if figureNum == 3
        disp('---- Times for Matrix Saxpy ----');
        for MatSize = [128, 512, 1024, 4096]
            MatMatClass.MatMatSaxpy(MatSize);
        end
    end

    if figureNum == 4
        disp('---- Times for Matrix Vector ----');
        for MatSize = [128, 512, 1024, 4096]
            MatMatClass.MatMatVec(MatSize);
        end
    end

    if figureNum == 5
        disp('---- Times for Matrix Direct ----');
        for MatSize = [128, 512, 1024, 4096]
            MatMatClass.MatMatDirect(MatSize);
        end
    end

end