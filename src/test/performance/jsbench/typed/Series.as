var size:int;
    // Declare class data.

  var array_rows:int;

  var TestArray:Vector.<Vector.<Number>>; // Array of arrays.
  
  var datasizes:Vector.<int> = new Vector.<int>(3,true);
  datasizes[0] = 10000;
  datasizes[1] = 100000;
  datasizes[2] = 1000000;

  var start=new Date();
  JGFrun(0);
  var elapsed=new Date()-start;
  print("metric time "+elapsed);
  function JGFsetsize(sizel:int):void {
    size = sizel;
  }

  function JGFinitialise():void {
    array_rows = datasizes[size];
    buildTestData();
  }

  function JGFkernel():void {
    Do();
  }

  function JGFvalidate():void {
    var ref:Vector.<Vector.<Number>> = new Vector.<Vector.<Number>>(4,true);
    for(var i=0;i<4;i++)
    {
      ref[i] = new Vector.<Number>(2,true);
    }
    
    ref[0][0] = 2.8729524964837996;
    ref[0][1] = 0.0;
    ref[1][0] = 1.1161046676147888;
    ref[1][1] = -1.8819691893398025;
    ref[2][0] = 0.34429060398168704;
    ref[2][1] = -1.1645642623320958;
    ref[3][0] = 0.15238898702519288;
    ref[3][1] = -0.8143461113044298;
    /*
     * // for 200 points double ref[][] = {{2.8377707562588803, 0.0},
     * {1.0457844730995536, -1.8791032618587762}, {0.27410022422635033,
     * -1.158835123403027}, {0.08241482176581083, -0.8057591902785817}};
     */
    for (var i:int = 0; i < 4; i++) {
      for (var j:int = 0; j < 2; j++) {
        var error:Number = Math.abs(TestArray[j][i] - ref[i][j]);
        
        if (error > 1.0e-12) {
          print("Validation failed for coefficient " + j + "," + i);
          print("Computed value = " + TestArray[j][i]);
          print("Reference value = " + ref[i][j]);
        }
        
        print( TestArray[j][i] );
      }
    }
  }

  function JGFtidyup():void {
    freeTestData();
  }

  function JGFrun(sizel:int):void {
    JGFsetsize(sizel);
    JGFinitialise();
    JGFkernel();
    JGFvalidate();
    //JGFtidyup();
  }
  
    /*
   * buildTestData
   * 
   */

  // Instantiate array(s) to hold fourier coefficients.
  function buildTestData():void {
    // Allocate appropriate length for the double array of doubles.

    TestArray = new Vector.<Vector.<Number>>(2,true); //double[2][array_rows];
    for(var i=0;i<2;i++)
    {
      TestArray[i] = new Vector.<Number>(array_rows);
    }
  }

  /*
   * Do
   * 
   * This consists of calculating the first n pairs of fourier coefficients of
   * the function (x+1)^x on the interval 0,2. n is given by array_rows, the
   * array size. NOTE: The # of integration steps is fixed at 1000.
   */

  function Do():void {
    var omega:Number; // Fundamental frequency.

    // Calculate the fourier series. Begin by calculating A[0].
    TestArray[0][0] = 2.0;
    TestArray[0][0] = TrapezoidIntegrate(0.0, // Lower bound.
        2.0, // Upper bound.
        1000, // # of steps.
        0.0, // No omega*n needed.
        0) / 2.0; 
        // 0 = term A[0].
    TestArray[1][0]=0.0;
    // Calculate the fundamental frequency.
    // ( 2 * pi ) / period...and since the period
    // is 2, omega is simply pi.

    omega = 3.1415926535897932;
    for (var i:int = 1; i < array_rows; i++) {
      // Calculate A[i] terms. Note, once again, that we
      // can ignore the 2/period term outside the integral
      // since the period is 2 and the term cancels itself
      // out.

      TestArray[0][i] = TrapezoidIntegrate(0.0, 2.0, 1000, omega * i, 1); // 1 =
                                        // cosine
                                        // term.

      // Calculate the B[i] terms.

      TestArray[1][i] = TrapezoidIntegrate(0.0, 2.0, 1000, omega * i, 2); // 2 =
                                        // sine
                                        // term.
    }
  }

  /*
   * TrapezoidIntegrate
   * 
   * Perform a simple trapezoid integration on the function (x+1)**x. x0,x1
   * set the lower and upper bounds of the integration. nsteps indicates # of
   * trapezoidal sections. omegan is the fundamental frequency times the
   * series member #. select = 0 for the A[0] term, 1 for cosine terms, and 2
   * for sine terms. Returns the value.
   */

  function TrapezoidIntegrate( x0:Number, // Lower bound.
       x1:Number, // Upper bound.
       nsteps:int, // # of steps.
       omegan:Number, // omega * n.
       select:int):Number // Term type.
  {
    var x:Number; // Independent variable.
    var dx:Number; // Step size.
    var rvalue:Number; // Return value.

    // Initialize independent variable.

    x = x0;

    // Calculate stepsize.

    dx = (x1 - x0) / nsteps;

    // Initialize the return value.

    rvalue = thefunction(x0, omegan, select) / 2.0;

    // Compute the other terms of the integral.

    if (nsteps != 1) {
      --nsteps; // Already done 1 step.
      while (--nsteps > 0) {
        x += dx;
        rvalue += thefunction(x, omegan, select);
      }
    }

    // Finish computation.

    rvalue = (rvalue + thefunction(x1, omegan, select) / 2.0) * dx;
    return (rvalue);
  }

  /*
   * thefunction
   * 
   * This routine selects the function to be used in the Trapezoid
   * integration. x is the independent variable, omegan is omega * n, and
   * select chooses which of the sine/cosine functions are used. Note the
   * special case for select=0.
   */

  function thefunction( x:Number, // Independent variable.
       omegan:Number, // Omega * term.
       select:int):Number // Choose type.
  {
    // Use select to pick which function we call.
    switch (select) {
      case 0:
        return (Math.pow(x + 1.0, x));

      case 1:
        return (Math.pow(x + 1.0, x) * Math.cos(omegan * x));

      case 2:
        return (Math.pow(x + 1.0, x) * Math.sin(omegan * x));
    }

    // We should never reach this point, but the following
    // keeps compilers from issuing a warning message.

    return (0.0);
  }
  
