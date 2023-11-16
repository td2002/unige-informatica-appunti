%Gruppo di lavoro:
% Mafodda Edoardo: 5302507
% Toscano Mattia: 5288636
% Trioli Davide: 5316731

% ES 1

d0 = 7;
d1 = 0;
m = 10*(d0+1)+d1; %80

A = zeros(m,3);
for i = 1:m
    A(i,:) = [1 (i/m) (i/m)^2];
end

[U_A, S_A, V_A] = svd(A);
[U_At, S_At, V_At] = svd(A');
EVal_AAt = eig((A*A'));
EVal_AtA = eig((A'*A));

O_A = orth(A);
O_At = orth(A');
N_A = null(A);
N_At = null(A');

%{
A trasforma da R3 in R80 e quindi non si perde alcuna dimensione nel nucleo
A' fa la trasformazione inversa e quindi si perde 77 dimensioni

O_A, U_A condividono le prime 3 colonne
N_At, V_At sono uguali a parte le prime 3 colonne che vengono tolte da N_At
%}


% ES 2

%prove con n crescenti
%n = 3;
%n = 10;
%n = 50;
n = 5;
B = zeros(n);

for i = 1:n
    for j = 1:n
        if (i==j) 
            B(i,j) = 1;
        end
        if (i<j) 
            B(i,j) = -1;
        end
        if (i>j) 
            B(i,j) = 0;
        end
    end
end

[U_B, S_B, V_B] = svd(B);
cond_B = cond(B);
division_sing_val = S_B(1,1)/S_B(n,n);

rank_B = zeros(1,2);

%rango prima della perturbazione (posiz. 1)
rank_B(1,1) = rank(B, eps-1);

%perturbazione
B_p = B;
B_p(n,1) = B(n,1) + (-2^(2-n));

%rango dopo perturbazione (posiz. 2)
rank_B(1,2) = rank(B_p);
%{
rank diminuisce poiché espandendo per Laplace sull'ultima riga il det per
l'errore esce -1 e per l'ultima colonna 1, risultando 0
%}

%autovalori dopo perturbazione
EVal_B_err = eig(B_p);
%sing val dopo perturbazione (quasi uguali a B originale: errore non dà
%fastidio)
S_p_B = svd(B_p);


% ES 3
y = zeros(m, 1);
for i = 1:m
    y(i,1) = sin(A(i,2));
end

% 1. soluzione con SVD
c1 = V_A * pinv(S_A) * U_A' * y;

% 2. soluzione con decomposizione QR
[Q_A, R_A, P_A] = qr(A);
c2 = P_A * (R_A \ (Q_A' * y));

% 3. soluzione con equazioni normali
c3 = (A' * A)^-1 * A' * y;

% 4. soluzione con comando built-in Matlab \
c4 = A\y;

% visuale compatta: matrice con vettori di soluzioni ...
C_solutions = [c1 c2 c3 c4];
% ... e matrice delle differenze tra tutte le soluzioni (molto basse)
C_diff = [(c1-c2), (c1-c3), (c1-c4), (c2-c3), (c2-c4), (c3-c4)];

