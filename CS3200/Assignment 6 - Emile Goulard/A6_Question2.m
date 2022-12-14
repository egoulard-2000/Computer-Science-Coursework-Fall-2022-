%{
    Emile Goulard
    uID: u1244855
    CS3200 - Assignment 6

    Summary:
        This class runs code pertaining to question 2 in the Assignment 6
        page. It will run the iterative solvers: Jacobi, Gauss-Seidel, and
        Successive Over-Relaxation (w=1.05).

        - figureNum: determines which figure to run. 
        insert 1 to run Jacobi Method
        insert 2 to run Gauss-Seidel Method
        insert 3 to run Successive Over-Relaxation

        - A1andB1: a boolean value that determines if we find the A1x=b1 
        or A2x=b2 for that iterative solver. Insert true for A1x=b1 and
        false for A2x=b2
%}

function [] = A6_Question2(figureNum, A1andB1)

% ---- Load the matrix data
    load A1.dat A1
    A1_matrix = spconvert(A1);

    load A2.dat A2
    A2_matrix = spconvert(A2);

    fileID = fopen('b1.dat');
    b1Text = textscan(fileID,'%f%f','HeaderLines',1);
    b1 = cell2mat(b1Text);
    fclose(fileID);

    fileID = fopen('b2.dat');
    b2Text = textscan(fileID,'%f%f','HeaderLines',1);
    b2 = cell2mat(b2Text);
    fclose(fileID);
    
% ---- Jacobi Method
    if figureNum == 1 && A1andB1 == true
    % ---- Jacobi Method for A1 and B1
        clear tolerance threshold n k x2
        n = height(b1); 
        x2 = zeros(1, n);

        tolerance = 1e-5;
        threshold = Inf;
        k = 0;

        tic
        while threshold >= tolerance
            x1=x2;
            for i=1:n
                s=0;
                for j=1:n
                    if j~=i
                        s = s + A1_matrix(i,j) * x2(j);
                    end
                end
                x2(i) = (b1(i)-s) / A1_matrix(i,i);
            end
    
            threshold = abs(x2 - x1);
            k = k + 1;
        end
        toc
        
        fprintf("Jacobi Iterations for A1/b1: %f\n", k);
        fprintf("Jacobi Solutions for A1/b1: %f\n", x2);
    end
    if figureNum == 1 && A1andB1 == false
    % ---- Jacobi Method for A2 and b2
        clear tolerance threshold n k x2
        n = height(b2); 
        x2 = zeros(1, n);

        tolerance = 1e-5; 
        threshold = Inf;
        k = 0;

        tic
        while threshold >= tolerance
            x1 = x2;
            for i=1:n
                s = 0;
                for j=1:n
                    if j~=i
                        s = s + A2_matrix(i,j) * x2(j);
                    end
                end
                x2(i) = (b2(i)-s) / A2_matrix(i,i);
            end
    
            threshold = abs(x2 - x1);
            k = k + 1;
        end
        toc
        
        fprintf("Jacobi Iterations for A2/b2: %f\n", k);
        fprintf("Jacobi Solutions for A2/b2: %f\n", x2);
    end

% ---- Gauss-Seidel Method
    if figureNum == 2 && A1andB1 == true
        % ---- Gauss-Seidel Method for A1 and b1
        clear tolerance threshold n k x2
        n = height(b1); 
        x2 = zeros(1, n);

        tolerance = 1e-5; 
        threshold = Inf;
        k = 0;

        tic
        while threshold > tolerance
            x1 = x2;
            for i=1:n
                s = 0;
                for j=1:i-1
                    s = s + A1_matrix(i,j) * x2(j);
                end
        
                for j=i+1:n
                    s = s + A1_matrix(i,j) * x1(j);
                end
                x2(i) = (b1(i)-s) / A1_matrix(i,i);
            end
    
            threshold = abs(x1 - x2);
            k = k + 1;
        end
        toc

        fprintf("Gauss-Seidel Iterations for A1/b1: %f\n", k);
        fprintf("Gauss-Seidel Solutions for A1/b1: %f\n", x2);
    end
    if figureNum == 2 && A1andB1 == false
        % ---- Gauss-Seidel Method for A2 and b2
        clear tolerance threshold n k x2
        n = height(b2); 
        x2 = zeros(1, n);

        tolerance = 1e-5; 
        threshold = Inf;
        k = 0;

        tic
        while threshold > tolerance
            x1 = x2;
            for i=1:n
                s = 0;
                for j=1:i-1
                    s = s + A2_matrix(i,j) * x2(j);
                end
        
                for j=i+1:n
                    s = s + A2_matrix(i,j) * x1(j);
                end
                x2(i) = (b2(i)-s) / A2_matrix(i,i);
            end
    
            threshold = abs(x1 - x2);
            k = k + 1;
        end
        toc

        fprintf("Gauss-Seidel Iterations for A2/b2: %f\n", k);
        fprintf("Gauss-Seidel Solutions for A2/b2: %f\n", x2);
    end

% ---- Successive Over-Relaxation
    if figureNum == 3 && A1andB1 == true
        % ---- Successive Over-Relaxation for A1 and b1
        clear tolerance threshold n k x2

        w = 1.05; %scalar relaxation factor
        n = height(b1);
        x2 = zeros(1, n);

        tolerance = 1e-5;
        threshold = Inf;
        k = 0;

        tic
        while threshold >= tolerance
            x1=x2;
            for i=1:n
                s=0;
                for j=1:n
                    if j~=i
                        s = s + A1_matrix(i,j) * x2(j);
                    end
                end
                x2(i) = (1-w)*x2(i) + w*(b1(i)-s) / A1_matrix(i,i);
            end
    
            threshold = abs(x2 - x1);
            k = k + 1;
        end
        toc

        fprintf("SOR Iterations for A1/b1: %f\n", k);
        fprintf("SOR Solutions for A1/b1: %f\n", x2);
    end
    if figureNum == 3 && A1andB1 == false
        % ---- Successive Over-Relaxation for A2 and b2
        clear tolerance threshold n k x2

        w = 1.05; %scalar relaxation factor
        n = height(b2);
        x2 = zeros(1, n);

        tolerance = 1e-5;
        threshold = Inf;
        k = 0;

        tic
        while threshold >= tolerance
            x1=x2;
            for i=1:n
                s=0;
                for j=1:n
                    if j~=i
                        s = s + A2_matrix(i,j) * x2(j);
                    end
                end
                x2(i) = (1-w)*x2(i) + w*(b2(i)-s) / A2_matrix(i,i);
            end
    
            threshold = abs(x2 - x1);
            k = k + 1;
        end
        toc

        fprintf("SOR Iterations for A2/b2: %f\n", k);
        fprintf("SOR Solutions for A2/b2: %f\n", x2);
    end

end