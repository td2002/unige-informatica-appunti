%Gruppo di lavoro:
% Mafodda Edoardo: 5302507
% Toscano Mattia: 5288636
% Trioli Davide: 5316731

% ES 1

d0 = 1;
d1 = 3;

n = 10*(d1 + 1) + d0; %41

A = diag(ones(1, n - 1), 1) + eye(n);

E = zeros(n);
E(n, 1) = 2^(-n);

%ES 1 PARTE 1

B = A+E;
VA = eig(A) ;
VB = eig(B) ;
n_ba = norm(B - A)/norm(A) ;
n_vbva = norm(VB - VA)/norm(VA);

%ES 1 PARTE 2

AtA = A'*A;
BtB = B'*B;

VAtA = eig(AtA) ;
VBtB = eig(BtB) ;
n_baT = norm(BtB - AtA)/norm(AtA) ;
n_vbvaT = norm(VBtB - VAtA)/norm(VAtA);


%ES 2

%ES 2 PARTE 1

n = 11; %nodi
A_Lomb = zeros(n);
%nodo 1
A_Lomb(7, 1) = 1;
A_Lomb(6, 1) = 1;
A_Lomb(5, 1) = 1;
A_Lomb(4, 1) = 1;
A_Lomb(3, 1) = 1;
A_Lomb(2, 1) = 1;
%nodo 2
A_Lomb(1, 2) = 1;
%nodo 3
A_Lomb(1, 3) = 1;
A_Lomb(10, 3) = 1;
%nodo 4
A_Lomb(1, 4) = 1;
A_Lomb(10, 4) = 1;
A_Lomb(5, 4) = 1;
%nodo 5
A_Lomb(1, 5) = 1;
A_Lomb(4, 5) = 1;
A_Lomb(6, 5) = 1;
A_Lomb(8, 5) = 1;
%nodo 6
A_Lomb(1, 6) = 1;
A_Lomb(5, 6) = 1;
A_Lomb(8, 6) = 1;
%nodo 7
A_Lomb(1, 7) = 1;
%nodo 8
A_Lomb(9, 8) = 1;
A_Lomb(6, 8) = 1;
A_Lomb(5, 8) = 1;
%nodo 9
A_Lomb(8, 9) = 1;
%nodo 10
A_Lomb(11, 10) = 1;
A_Lomb(4, 10) = 1;
A_Lomb(3, 10) = 1;
%nodo 11
A_Lomb(10, 11) = 1;

%ES 2 PARTE 2

D = diag([6 1 2 3 4 3 1 3 1 3 1]);

G = A_Lomb * (D^-1);
% G è stocastica

[eigvectG, eigvalG] = eig(G, 'nobalance');
% serve per evitare il balancing automatico dei dati che può comportare
% valori inaccurati
% ultimi 3 sono quasi zeri

%ES 3 parte 1

A3 = [1 -1 2 ; -2 0 5 ; 6 -3 6];

% calcolo autovalori e autovettori per conferme
[eigvectA3, eigvalA3] = eig(A3);

%{
metodo di test, uno a uno (di prova, non implementato)
w1_1 = (A3 * v3_init1) / (norm(A3 * v3_init1));
w2_1 = (A3 * w1_1) / (norm(A3 * w1_1));
w3_1 = (A3 * w2_1) / (norm(A3 * w2_1));
w4_1 = (A3 * w3_1) / (norm(A3 * w3_1));
w5_1 = (A3 * w4_1) / (norm(A3 * w4_1));
%}

%{
si mettono i vettori man mano calcolati e normalizzati
dentro una matrice temp di dimensioni apposite, partendo dal
primo dato in input nella 1a riga, poi si utilizza
l'ultima riga (contenente l'ultimo vettore calcolato)
%}

iteration_max = 10;
temp = zeros(iteration_max,3);

% calcolo tramite primo vettore input
temp(1,:) = [1 1 1];
for i = 2:iteration_max
    temp(i,:) = ((A3 * temp(i-1,:)') / (norm(A3 * temp(i-1,:)')));
end
lambda_1 = temp(iteration_max,:) * A3 * temp(iteration_max,:)';

% calcolo tramite secondo vettore input
temp(1,:) = [3 10 4];
for i = 2:iteration_max
    temp(i,:) = ((A3 * temp(i-1,:)') / (norm(A3 * temp(i-1,:)')));
end
lambda_2 = temp(iteration_max,:) * A3 * temp(iteration_max,:)';
%non viene come il max eigval poiché il vettore in partenza è dipendente
%con gli autovettori corrispondente ad autovalori -1 e 3
proof_dependency_v1 = rank([eigvectA3(:,1) eigvectA3(:,3) [1;1;1]]);
proof_dependency_v2 = rank([eigvectA3(:,1) eigvectA3(:,3) [3;10;4]]);
% da qui si nota come si riesca a ottenere il vettore di partenza
% [3; 10; 4]' a partire da solamente due degli autovettori di A;
% essi sono quelli corrispondenti agli eigval -1, 3 e quindi il metodo
% delle potenze ottiene il maggiore eigval solo tra questi due

% calcolo velocità di convergenza tramite mdp
convegence_speed_1 = (abs(lambda_2/lambda_1))^iteration_max;

% ES 3 parte 2

p = 18;
% p=4 ad es. non funziona poiché essendo a metà
% tra 2 autovalori di A non converge
% quando p va verso -∞ oppure +∞ velocità cresce
iteration_max = 10;
temp2 = zeros(iteration_max,3);
B3 = (A3-p*eye(3))^-1;
% calcolo tramite primo vettore input (inversa)
temp2(1,:) = [1 1 1];
for i = 2:iteration_max
    temp2(i,:) = ((B3 * temp2(i-1,:)') / (norm(B3 * temp2(i-1,:)')));
end
mu_1 = temp2(iteration_max,:) * B3 * temp2(iteration_max,:)';

% calcolo autovalore di A partendo da quello trovato di B
lambda_inv = (1/(mu_1))+p;

% calcolo velocità di convergenza tramite mdp inverse
mu_2 = 1/(lambda_2-p);
convegence_speed_2 = (abs(mu_2/mu_1))^iteration_max;



