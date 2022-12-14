%{
    Emile Goulard
    uID: u1244855
    CS3200 - Assignment 3

    Summary:
        Answers Question 3. 

        If you want to create the convergence plot for
        3 Newton-Cotes formulas: specify the N and set "isNewtonCotesPLot"
        to true.

        If you want to print out the results for Gaussian Quadrature for 
        N = 2,3,4,5: set "isNewtonCotesPLot" to false. N can be set to some
        value, but it will have no effect on the final output.
        
%}
function [ ] = A3_Question3(N, isNewtonCotesPlot)
close all
a = 0;
b = 2*pi;
actual_sol = 6.305171;
% ------ Question 3 Convergence Plot ------
    title('Convergence Plot for 3 Newton-Cotes Formulas');
    hold on

if isNewtonCotesPlot == true
    % ---- Composite Midpoint Rule ---- 
        summation = zeros(1, N);
        N_Values = zeros(1, N);
        x = zeros(1, N);
        y = zeros(1, N);
        w = zeros(1, N);
        deltaX = (b - a) / N;

        x(1) = a + (1 - 0.5) * deltaX;
        w(1) = deltaX;
        y(1) = (1 + sin(x(1)) * cos(2*x(1)/3)*sin(4*x(1)));
        summation(1) = w(1) * y(1);
        N_Values(1) = 1;

        for i=2:N
            x(i) = a + (i - 0.5) * deltaX;
            y(i) = 1 + sin(x(i)) * cos(2*x(i)/3)*sin(4*x(i));
            w(i) = deltaX;
            N_Values(i) = i;

            summation(i) = w(i) * y(i) + summation(i-1);
            %plot(N_Values(i), summation(i), 'ro', 'lineWidth', 1);
        end

        plot(abs(summation-actual_sol), 'b', 'lineWidth', 1);

        clear summation N_Values x y w deltaX

    %---- Composite Trapezoidal Rule ----
        summation = zeros(1, N);
        N_Values = zeros(1, N);
        x = zeros(1, N);
        y = zeros(1, N);
        w = zeros(1, N);
        deltaX = (b - a) / (N - 1);

        N_Values(1) = 1;
        x(1) = a + (1 - 1) * deltaX;
        w(1) = deltaX / 2;
        y(1) = (1 + sin(x(1)) * cos(2*x(1)/3)*sin(4*x(1)));
        summation(1) = w(1) * y(1);

        for i=2:N-1
            x(i) = a + (i - 1) * deltaX;
            w(i) = deltaX;
            y(i) = 1 + sin(x(i)) * cos(2*x(i)/3)*sin(4*x(i));
            N_Values(i) = i;

            summation(i) = w(i) * y(i) + summation(i-1);
        end

        x(N) = a + (N - 1) * deltaX;
        y(N) = (1 + sin(x(N)) * cos(2*x(N)/3)*sin(4*x(N)));
        w(N) = deltaX / 2;
        summation(N) = w(N) * y(N) + summation(N-1);

        plot(abs(summation-actual_sol), 'r', 'lineWidth', 1);

        clear summation N_Values x y w deltaX

    %---- Composite Simpson's Rule ---- 
        summation = zeros(1, 2*N+1);
        N_Values = zeros(1, 2*N+1);
        x = zeros(1, 2*N+1);
        y = zeros(1, N);
        w = zeros(1, 2*N+1);
        deltaX = (b - a) / (2 * N);

        x(1) = a + (1 - 1) * deltaX;
        w(1) = deltaX / 3;
        y(1) = (1 + sin(x(1)) * cos(2*x(1)/3)*sin(4*x(1)));
        N_Values(1) = 1;
        summation(1) = w(1) * y(1);

        for i=2:2*N
            x(i) = a + (i - 1) * deltaX;
            y(i) = 1 + sin(x(i)) * cos(2*x(i)/3)*sin(4*x(i));

            %check if i is even or odd and set the w(i) value
            if mod(i, 2) == 0
                w(i) = (4 * deltaX) / 3;
            else
                w(i) = (2 * deltaX) / 3;
            end

            N_Values(i) = i;
            summation(i) = w(i) * y(i) + summation(i-1);
        end

        x(2*N+1) = a + (2*N+1 - 1) * deltaX;
        y(2*N+1) = (1 + sin(x(2*N+1)) * cos(2*x(2*N+1)/3)*sin(4*x(2*N+1)));
        w(2*N+1) = deltaX / 3;
        summation(2*N+1) = w(2*N+1) * y(2*N+1) + summation(2*N);

        plot(abs(summation-actual_sol), 'g', 'lineWidth', 1);

        clear summation N N_Values x y w deltaX

    %Legend
    legend('Composite Midpoint Rule', 'Composite Trapezoidal Rule', 'Composite Simpsons Rule', 'Location', 'northeast');
    xlabel("N");
    ylabel("Integral Value Error");
    %xlim([2 1200]);
    %xticks(2:2:1200);
    box on;
    grid on;

else
    %---- Gaussian Quadrature Rule ---- 
    disp('Gaussian Quadrature')
        temp = (b - a) / 2;
        summation = zeros(1, 4);
            %---- N = 2
                N = 2;
                y = zeros(1, N);
                x = zeros(1, N);
                w = zeros(1, N);

                x(1) = 1 / sqrt(3);
                w(1) = 1.0000;

                x(2) = -1 / sqrt(3);
                w(2) = 1.0000;

                sum = 0;
                for i=1:N
                    y(i) = (1 + sin(temp * x(i) + (a + b) / 2) * cos(temp * x(i) + (a + b) / 2)*sin(4* (temp * x(i) + (a + b) / 2)));
                    sum = sum + w(i) * y(i);
                end

                summation(N-1) = temp * sum;
            
            clear N y x w sum
            %---- N = 3
                N = 3;
                y = zeros(1, N);
                x = zeros(1, N);
                w = zeros(1, N);

                x(1) = 0;
                w(1) = 8 / 9;

                x(2) = sqrt(3 / 5);
                w(2) = 5/9;

                x(3) = -sqrt(3 / 5);
                w(3) = 5/9;

                sum = 0;
                for i=1:N
                    y(i) = (1 + sin(temp * x(i) + (a + b) / 2) * cos(temp * x(i) + (a + b) / 2)*sin(4* (temp * x(i) + (a + b) / 2)));
                    sum = sum + w(i) * y(i);
                end

                summation(N-1) = temp * sum;

            clear N y x w sum
            %---- N = 4
                N = 4;
                y = zeros(1, N);
                x = zeros(1, N);
                w = zeros(1, N);

                x(1) = sqrt((3 - 2 * sqrt(6/5)) / 7);
                w(1) = (18 + sqrt(30)) / 36;

                x(2) = -sqrt((3 - 2 * sqrt(6/5)) / 7);
                w(2) = (18 + sqrt(30)) / 36;

                x(3) = sqrt((3 + 2 * sqrt(6/5)) / 7);
                w(3) = (18 - sqrt(30)) / 36; 

                x(4) = -sqrt((3 + 2 * sqrt(6/5)) / 7);
                w(4) = (18 - sqrt(30)) / 36; 

                sum = 0;
                for i=1:N
                    y(i) = (1 + sin(temp * x(i) + (a + b) / 2) * cos(temp * x(i) + (a + b) / 2)*sin(4* (temp * x(i) + (a + b) / 2)));
                    sum = sum + w(i) * y(i);
                end

                summation(N-1) = temp * sum;

            clear N y x w sum
            %---- N = 5
                N = 5;
                y = zeros(1, N);
                x = zeros(1, N);
                w = zeros(1, N);

                x(1) = 0;
                w(1) = 128 / 225;

                x(2) = (1 / 3) * sqrt(5 - 2 * sqrt(10 / 7));
                w(2) = (322 + 13 * sqrt(70)) / 900;

                x(3) = -(1 / 3) * sqrt(5 - 2 * sqrt(10 / 7));
                w(3) = (322 + 13 * sqrt(70)) / 900;

                x(4) = (1 / 3) * sqrt(5 + 2 * sqrt(10 / 7));
                w(4) = (322 - 13 * sqrt(70)) / 900; 

                x(5) = -(1 / 3) * sqrt(5 + 2 * sqrt(10 / 7));
                w(5) = (322 - 13 * sqrt(70)) / 900; 

                sum = 0;
                for i=1:N
                    y(i) = (1 + sin(temp * x(i) + (a + b) / 2) * cos(temp * x(i) + (a + b) / 2)*sin(4* (temp * x(i) + (a + b) / 2)));
                    sum = sum + w(i) * y(i);
                end

                summation(N-1) = temp * sum;

            for i=1:N-1
                fprintf('N == %d: ', i + 1);
                disp(summation(i));
            end

end

end