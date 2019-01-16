figure
data = csvread('data.csv');
data = data(:,1:100);
[X,Y] = meshgrid(0:.01:.99,0:.01:.99);
surf(X,Y,data);
xlabel('Infection Rate');
ylabel('Inoculation Rate');
title('Effect of Infection and Inoculation Rate on Disease Spreading');
c = colorbar;
c.Label.String = 'Number of Iterations';

figure
data2 = csvread('data2.csv');
data2 = data2(:,1:100);
[X,Y] = meshgrid(0:.01:.99,0:.01:.99);
surf(X,Y,data2);
xlabel('Infection Rate');
ylabel('Inoculation Rate');
title('Effect of Infection and Inoculation Rate on Herd Immunity');
c = colorbar;
c.Label.String = 'Fraction of Susceptible Population Who Escaped Infection';