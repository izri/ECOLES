%function [ instants times ] = poisson( varargin )
 % Generateur d’instants d’arrives d’un processus de Poisson.
 % poisson( b, start, end, )
 % poisson( b, end );
 % b = mu.
 % start = debut de la file.
 % end = fin de la file.
 function [ instants times ] =poisson(lambda, pstart, pend)
varargin={2, 1, 10};
% if nargin > 1
% b = varargin{1};
% pstart = varargin{2};
% else
% error('Too few arguments ( < 2 )');
% end;
% 
% if ( nargin == 2 )
%                 pstart = 0;
%                 pend = varargin{2};
% end;
% 
% if nargin > 2
%                 pend = varargin{3};
% end;
% 
% if nargin > 3
%                 error('Too many arguments ( > 3 )');
% end;
%lambda = varargin{1};
%pstart = varargin{2};

%pend = varargin{3}; %fin de simul

instants(1,1) = pstart;
i = 1;
while 1
time = -log(rand)/lambda; %loiexp( b );
if ( time + instants(i) > pend ) break;
end
times(i) = time;
i = i + 1;
instants(i) = instants(i-1) + times(i-1);
end