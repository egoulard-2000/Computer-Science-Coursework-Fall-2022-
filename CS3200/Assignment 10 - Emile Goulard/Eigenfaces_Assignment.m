clear all, close all, clc

load allFaces.mat

allPersons = zeros(n*6,m*6); % Make an array to fit 36 faces
count = 1;
for i=1:6 % 6 x 6 grid of faces
for j=1:6 allPersons(1+(i-1)*n:i*n,1+(j-1)*m:j*m) ...
=reshape(faces(:,1+sum(nfaces(1:count-1))),n,m); count = count + 1;
end
end
imagesc(allPersons), colormap gray

pause(5)


% We use 36 people for the training data
trainingFaces = faces(:,1:sum(nfaces(1:36)));
avgFace = mean(trainingFaces,2);  % size n*m by 1;

% compute eigenfaces on mean-subtracted training data
X = trainingFaces-avgFace*ones(1,size(trainingFaces,2));
[U,S,V] = svd(X,'econ');

% Show average face

figure, axes('position',[0  0  1  1]), axis off
imagesc(reshape(avgFace,n,m)), colormap gray

pause(5)

% Plot singular values

figure, plot(diag(S),'-o')

%% Part f - Plot median of singular values
%figure, plot(median(diag(S)),'-o')

pause(5)

for i=1:1  % plot the first eigenface
    figure;
    imagesc(reshape(U(:,i),n,m)); colormap gray;
end

%% Part a (uncomment when you get here)
%{
for i=1:3  % plot the first eigenface
    figure;
    imagesc(reshape(U(:,i),n,m)); colormap gray;
end
%}

%% Part f for Assignment 10 (Uncomment this when you reach the question)

%{
    % Singular Value 500
    figure;
    imagesc(reshape(U(:,500),n,m)); colormap gray;

    % Singular Value 1000
    figure;
    imagesc(reshape(U(:,1000),n,m)); colormap gray;

    % Singular Value 1500
    figure;
    imagesc(reshape(U(:,1500),n,m)); colormap gray;

    % Singular Value 2000
    figure;
    imagesc(reshape(U(:,2000),n,m)); colormap gray;
%}

pause(5)

%% Now show eigenface reconstruction of your photo

%% Read in your photo and reshape it to fit in the matrix

%% Part b, c and d
% ---- Uncomment either the 'My_Face', 'My_Face_Rotation', or 'Photo_Dog'
% ---- to produce those results

YourFace= imresize(double(rgb2gray(imread('My_Face','jpeg'))),[192,168]);
% YourFace= imresize(double(rgb2gray(imread('My_Face_Rotation','jpeg'))),[192,168]);
% YourFace= imresize(double(rgb2gray(imread('Photo_Dog','jpeg'))),[192,168]);
figure;
imagesc(reshape(YourFace,n,m)), colormap gray

pause(5)

YourFace1=reshape(YourFace,32256,1);

%% Now do face recognition to see how many eigenfaces it takes to recognize yourself

testFaceMS = YourFace1 - avgFace;
figure;
for r=25:25:2275
    reconFace = avgFace + (U(:,1:r)*(U(:,1:r)'*testFaceMS));
    imagesc(reshape(reconFace,n,m)), colormap gray
    title(['r=',num2str(r,'%d')]);
    pause(0.5)
end




