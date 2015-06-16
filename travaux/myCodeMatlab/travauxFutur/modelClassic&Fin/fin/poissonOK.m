
 % Generateur d’instants d’arrives d’un processus de Poisson.
 % poisson( b, start, end, )
 % b = mu.
 % start = debut de la file.
 % end = fin de la file.
function [ instants times ] =poisson(lambda, pstart, pend)
instants(1) = pstart; %avant c  était instants(1,1) = pstart;
i = 1;
while 1
time = -log(rand)/lambda; %loiexp( b );
if ( time + instants(i) > pend ) break;
end
times(i) = time;
i = i + 1;
instants(i) = instants(i-1) + times(i-1);
end