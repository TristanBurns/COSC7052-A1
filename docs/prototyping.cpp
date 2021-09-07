// while ((opts = getopt (argc, argv, "vn:m:s:")) != -1)
//     switch (opts)
//       {
//       case 'v':
//         verbose = true;
//         break;
//       case 'n':
//         n = atoi(optarg);
//         break;
//       case 'm':
//         m = atoi(optarg);
//         break;
//       case 's':
//         useseed = true;
//         seed = atoi(optarg);
//         break;
//       case '?':
//         std::cout << "Unknown Arugment Error";
//         return 1;
//       default:
//         abort ();
// }
    // params = ParseArguments(argc, argv);
    
    // verbose = params.verbose;
    // n=params.n;
    // m=params.m;
    // useseed = params.useseed;
    // seed = params.seed;

    // int p[m][n];
    // int** p = new int[m][n]; 
    int** p = new int*[m];
    for(int j = 0; j < m; ++j)
    {
        p[j] = new int[n];
    }    

    // int q[m][m];
    int** q = new int*[m];
    for(int j = 0; j < m; ++j)
    {
        q[j] = new int[n];
    }    


    void Mutate(int *q, int n, int m)
{
    int mu;

    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < n; j++)
        {
            mu = (std::rand() % n);
            if (mu == 0)
            {
                (q(i, j)) = 1 - (q(i, j));
            }
        }

    }
    return;
}




void Mutate(int *q, int n, int m)
{
    int mu;
    for (int i = 0; i < m; i++)
    {
        
        for (int j = 0; j < n; j++)
        {
            mu = ((std::rand() % n)==0);
            q(i, j) = (q(i, j))*(1-mu) + (1 - (q(i, j)))*(mu);
        }

    }
    return;
}


void MutateVerbose(int *q, int n, int m)
{
    int mu;
    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < n; j++)
        {
            mu = ((std::rand() % n)<1);
            q(i, j) = (q(i, j))*(1-mu)+ (1 - (q(i, j)))*mu;
            std::cout << " " << q(i, j) << " ";
        }
        std::cout << std::endl;
    }
    return;
}

void Mutate(int *q, int n, int m)
{
    int mu;
    for (int i = 0; i < m; i++)
    {
        
        for (int j = 0; j < n; j++)
        {
            mu = ((std::rand() % n)==0);
            q(i, j) = (q(i, j))*(1-mu) + (1 - (q(i, j)))*(mu);
        }

    }
    return;
}

void MutateVerbose(int *q, int n, int m)
{
    int mu;
    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < n; j++)
        {
            mu = ((std::rand() % n)<1);
            q(i, j) = (q(i, j))*(1-mu)+ (1 - (q(i, j)))*mu;
            std::cout << " " << q(i, j) << " ";
        }
        std::cout << std::endl;
    }
    return;
}


GenAlgParams ParseArguments(int argc, char *argv[])
{
    int opts;
    GenAlgParams params;
    while ((opts = getopt(argc, argv, "vn:m:s:")) != -1)
    {
        switch (opts)
        {
        case 'v':
            params.verbose = true;
            break;
        case 'n':
            params.n = atoi(optarg);
            std::cout << "n = " << params.n << std::endl;
            break;
        case 'm':
            params.m = atoi(optarg);
            std::cout << "m = " << params.m << std::endl;
            break;
        case 's':
            params.useseed = true;
            params.seed = atoi(optarg);
            std::cout << "seed = " << params.seed << std::endl;
            break;
        case '?':
            std::cout << "Unknown Arugment Error";
            break;
        default:
            abort();
        }
    }
    return params;
}


struct GenAlgParams {
    bool verbose;
    int n;
    int m;
    bool useseed;
    int seed;
};

GenAlgParams ParseArguments(int argc, char *argv[]);