%{
    Emile Goulard
    uID: u1244855
    CS3200 - Assignment 6

    Summary:
        Helper class for A6_Question1.m. It will be responsible
        for timing each Matrix class (Dot, Outer, Saxpy, Vector, and
        Direct)
%}
classdef MatMatClass
    methods (Static)

        function MatMatDot(MatSize)

            A = zeros(MatSize, MatSize);
            B = zeros(MatSize, MatSize);

            [m,p] = size(A);
            [p,n] = size(B);

            clear tic toc;
            tic
            C = zeros(m,n);
            for j=1:n
            % Compute jth column of C
                for i=1:m  
                    C (i,j) = A(i,:)*B(:,j);
                end
            end

            % Show Execution Time
            fprintf('For Matrices of Size: %i\n', MatSize);
            toc
            fprintf('\n');
        end

        function MatMatOuter(MatSize)
            
            A = zeros(MatSize, MatSize);
            B = zeros(MatSize, MatSize);

            [m,p] = size(A);
            [p,n] = size(B);

            clear tic toc;
            tic
            C = zeros(m,n);
            for k=1:p
                % Add in k-th outer product
                C = C + A(:,k)*B(k,:);
            end

            % Show Execution Time
            fprintf('For Matrices of Size: %i\n', MatSize);
            toc
            fprintf('\n');
        end

        function MatMatSaxpy(MatSize)

            A = zeros(MatSize, MatSize);
            B = zeros(MatSize, MatSize);

            [m,p] = size(A);
            [p,n] = size(B);

            clear tic toc;
            tic
            C=zeros(m,n);
            for j=1:n
                % Compute the jth column of C
                for k=1:m
                    C(:,j) = C(:,j) + A(:,k)*B(k,j);
                end
            end
            
            % Show Execution Time
            fprintf('For Matrices of Size: %i\n', MatSize);
            toc
            fprintf('\n');
        end

        function MatMatVec(MatSize)

            A = zeros(MatSize, MatSize);
            B = zeros(MatSize, MatSize);

            [m,p] = size(A);
            [p,n] = size(B);

            clear tic toc;
            tic
            C = zeros(m,n);
            for j=1:n
                % Compute j-th column of C.
                C(:,j) = C(:,j) + A*B(:,j);
            end
            
            % Show Execution Time
            fprintf('For Matrices of Size: %i\n', MatSize);
            toc
            fprintf('\n');
        end

        function MatMatDirect(MatSize)
            
            A = zeros(MatSize, MatSize);
            B = zeros(MatSize, MatSize);

            [m,r] = size(A);
            [r,n] = size(B);

            clear tic toc;
            tic
            C = zeros(m,n);
            for j=1:n
                for i=1:m
                    for k=1:r
                        C(i,j) = C(i,j) + A(i,k)*B(k,j);
                    end
                end
            end
            
            % Show Execution Time
            fprintf('For Matrices of Size: %i\n', MatSize);
            toc
            fprintf('\n');
        end
        
    end
end