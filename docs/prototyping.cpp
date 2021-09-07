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