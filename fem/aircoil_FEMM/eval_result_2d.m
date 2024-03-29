M = csvread('output_2d_fein.csv');
I = M(:,1);
y = M(:,2);
F = M(:,4);
Eco = M(:,5);
Emag = M(:,6);

%F_from_Eco = [0; diff(Eco)./ (diff(y)*0.001)];  %y is in mm

%Extend to positive y
Iext = [I;I];
yext = [y;-y];
Fext = [F;-F];

%scatter3(I,y,F);

zlabel('F/N')
xlabel('I/A')
ylabel('y/mm')


Igrid = 0:1:30;
ygrid = -20:0.25:20;

Fgrid = griddata(Iext,yext,Fext,Igrid,ygrid');

%scatter3(Iext,yext,Fext);
%hold on;
surf(Igrid,ygrid,Fgrid);
%hold off;

%test
% subplot(2,1,1)
% plot(y,Eco,'b-','LineWidth',2)
% hold on;
% plot(y,Emag,'r-','LineWidth',1)
% hold off;
% ylabel('E/Ws')
% xlabel('y/mm')
% 
% subplot(2,1,2)
% plot(y,F,'b-','LineWidth',2)
% hold on;
% plot(y,F_from_Eco,'r-','LineWidth',1)
% hold off;
% ylabel('F/N')
% xlabel('y/mm')
