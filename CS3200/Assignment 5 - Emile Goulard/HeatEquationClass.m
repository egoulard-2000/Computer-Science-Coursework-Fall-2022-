%{
    Emile Goulard
    uID: u1244855
    CS3200 - Assignment 5

    Summary:
        This is a helper class meant to calculate the 1D Heat Equation
        and plot the diffusion of heat. DO NOT RUN THIS CLASS. Instead,
        run "A5.m"

    Methods:
        "Calcuate(N, deltaT, isFigure1)"
            - N: the number of points for plotting temperature
            - deltaT: delta time (in seconds)
            - isFigure1: boolean for dictating which subdivsion method to
            plot

%}
classdef HeatEquationClass
    methods (Static)
        function Calculate(N, deltaT, isFigure1)
        % ---- Variable Setup
            a = 0.035; % alpha
            L = 2.5; % length
        
            deltaX = L/N;
            x = deltaX/2:deltaX:L-deltaX/2; % place at center of each N
            tf = 5; % final time
            t = 0:deltaT:tf; % time steps
            lenTime = length(t) / deltaT;
        
            Tinitial = 20;
            Tstart = 60;
            Tend = 20;
            T = Tinitial*ones(1, N); % Temperature Array
            
        % ---- Solving 1D Heat Equation
            dUdt = zeros(1, N);
            for i=1:lenTime
                for j=2:N-1
                    dUdt(j) = (a * deltaT * (T(j+1) - 2 * T(j) + T(j-1))) / deltaX^2;
                end
                % Set boundary cases
                dUdt(1) = (a * deltaT * (T(2) - 2 * T(1) + Tstart)) / deltaX^2;
                dUdt(N) = (a * deltaT * (Tend - 2 * T(N) + T(N-1))) / deltaX^2;
                
                % Update the temperature along that graph
                T = T + (deltaT * dUdt);
            end
        
        % ---- Plotting Diffusion of Heat 
            if(isFigure1) % 1st Subdivsion
                if(N == 8)
                    plot(x, T, 'r', 'LineWidth', 1.5); % N = 8 RED
                end
                if(N == 16)
                    plot(x, T, 'g', 'LineWidth', 1.5); % N = 16 GREEN
                end
                if(N == 32)
                    plot(x, T, 'b', 'LineWidth', 1.5); % N = 32 BLUE 
                end
                if(N == 64)
                    plot(x, T, 'm', 'LineWidth', 1.5); % N = 64 MAGENTA
                end
            
                % Legend
                    title('1D Heat Diffusion Plot (1st Subdivision: delta time = 0.01s)');
                    legend('N = 8', 'N = 16', 'N = 32', 'N = 64');
                    xlabel("Length (cm)");
                    ylabel("Temperature (Celsius)");
                    ylim([15, 60]);
                    box on;
                    grid on;

            else % 2nd Subdivsion
                if(deltaT == 0.001)
                    plot(x, T, 'r', 'LineWidth', 1.5); % delta time = 0.001 RED
                end
                if(deltaT == 0.01)
                    plot(x, T, 'g', 'LineWidth', 1.5); % delta time = 0.01 GREEN
                end
                if(deltaT == 0.1)
                    plot(x, T, 'b', 'LineWidth', 1.5); % delta time = 0.1 BLUE 
                end

                % Legend
                    title('1D Heat Diffusion Plot (2nd Subdivision: N = 32)');
                    legend('delta time = 0.1', 'delta time = 0.01', 'delta time = 0.001');
                    xlabel("Length (cm)");
                    ylabel("Temperature (Celsius)");
                    ylim([15, 60]);
                    box on;
                    grid on;
            end
        end
    end
end