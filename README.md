# Geographic Information System (GIS)

## Project Outcomes:
Develop a C++ program that uses:
- Dynamic arrays
- Memory management in classes (rule of three)
- Arrays of objects
- Multiple user-defined classes
- Test case reading

## Preparatory Readings:
- ZyBook primer chapters
- ZyBook chapter 2, 3

## **Warning: Never Modify Any Provided Files!**
- It can be exploited for cheating!
- Totally mess up with the grading process.
- **It will be graded as cheating!**
- I will officially announce if any modification is necessary in rare cases.

## Project overview:
Geographic Information Systems (GIS) are a useful application of technology to
the field of Geography. GIS tools are used in systems such as GCCS, often used
by the military for mission planning and high-level navigation. They are also
used by municipalities for managing resources such as monitoring watersheds for
testing purposes. County tax assessors likewise use such tools for assessing
taxes on property owners.

All of these applications involve efficient and accurate querying of points (for
example a mouse click) to determine whether a query is inside a particular
polygon. The purpose of such queries is often to report the name of the polygon
that contains the query point. The polygons used in GIS systems are often
referred as **parcels**.

Checking whether a point is inside a polygon depends on how the polygon is
stored. For this project, we'll work with convex polygons only, this enables us
to simplify the inclusion check a bit. In our case, polygons will be stored as a
list of vertices given in the clockwise order. Thus, checking if a point is
inside a polygon involves checking whether the point lies **on or to the right**
of all edges if we treat every edge as a directed line following the clockwise
direction.

To check the "on or right to" relation of a point to a directed line. Given
three points, to determine the location of a point **p3** related to the line
from point **p1** to point **p2**, we can use the following formula

```
(p2.x - p1.x)(p3.y - p1.y) - (p2.y - p1.y)(p3.x - p1.x)
```

to calculate the cross product of two vectors `p2->p1` and `p3->p1`. If this
value is negative, **p3** is on the right to the edge from **p1** to **p2**. If
this value is zero, it is on the edge. **It is strongly recommended to make
a private bool function like `bool isRightOrOn(...)` to check on or to the right
relation of three points!**

## Project Requirements:
Your application must function as described below:
1. Your program shall adhere to the test suites provided [here](test/). Read
   the tests and create the required files, classes, and methods. This means
   that all tests must pass in their current configuration.
1. A [makefile](makefile) is provided. Read it to have some understanding of
   the project. Never modify it!.
1. Additionally, you must create a user application that allows a user to
   specify an input file which conforms to the [Sample
   data](#sample-polygonal-data) format given below.
    - Data will be given as alternating `x` and `y` values.
    - Each line of the input file will contain a single polygon.
    - All coordinate values are integer values.
    - The first parcel in the sample data below is a 2x2 square with the bottom
    left vertex at (0,0) and a rectangle that is two units high and six units
    wide with a bottom left vertex at (0,2).
    - Not all inputs will be axis-aligned rectangles, they are just good
    exemplars due to their simplicity.
1. The program must then allow queries to be submitted in the form of **x** and
   **y** coordinates and should report the _title_ of the polygon which contains
   the query point.
    - The user should be prompted for the x coordinate, then prompted for the y
      coordinate as seen in [Sample run](#sample-run) below.

## Sample polygonal data:
This sample data is found in [simple-polygons.txt](simple-polygons.txt). A more
complicated input file is in [polygons.txt](polygons.txt), for when you are
ready to test your program against something more complicated.

```
squareParcel 0 0 0 2 2 2 2 0
wideRectangleParcel 0 2 0 4 6 4 6 2
```

## Sample run (make simple-run):
You should be able to reproduce the following sample runs! Pay attention to the
returned parcel names returned from the query of points!

```
Please enter the file with the polygon data: bad-file-name.zz
bad-file-name.zz
Invalid file name!
Please enter the file with the polygon data: simple-polygons.txt
simple-polygons.txt
File read successfully!
Coordinates of query point (non-integer quits)
    x: 1
    y: 1
Query point is inside: squareParcel
Coordinates of query point (non-integer quits)
    x: 3
    y: 3
Query point is inside: wideRectangleParcel
Coordinates of query point (non-integer quits)
    x: 7
    y: 7
Query point is inside: Not Found
Coordinates of query point (non-integer quits)
    x: q
Have a great day!
```

## Sample run (make complex-run):
```
Please enter the file with the polygon data: polygons.txt
polygons.txt
File read successfully!
Coordinates of query point (non-integer quits)
    x: 2
    y: 14
Query point is inside: Not Found
Coordinates of query point (non-integer quits)
    x: 0
    y: 2
Query point is inside: SantaRosaSoundWatershed
Coordinates of query point (non-integer quits)
    x: 2
    y: 8
Query point is inside: BayouChico
Coordinates of query point (non-integer quits)
    x: 5
    y: 9
Query point is inside: PensacolaBayWatershedNorth
Coordinates of query point (non-integer quits)
    x: 5
    y: 5
Query point is inside: ThePond
Coordinates of query point (non-integer quits)
    x: 5
    y: 0
Query point is inside: PensacolaBayWatershedSouth
Coordinates of query point (non-integer quits)
    x: 7
    y: 4
Query point is inside: WaterHoldingArea
Coordinates of query point (non-integer quits)
    x: q
Have a great day!

```

## Implementation Notes:
1. Read the [Test cases](test/) to understand the design of the classes.
1. Read the [autograding configuration](.github/classroom/autograding.json) to
   understand the autograding process.
1. Read the [makefile](makefile) on the targets to run. No need to understand
   the details in this file.
1. Create a project that is object oriented, therefore there should be several
   classes to create.
1. The input files are provided. They match the exact format given above.
1. Your program must compile and pass all tests.
    - This application must be compiled by running `make main` and shall create
    an executable file called `main`.
    - All tests must pass by running together with `make test-all`. You can run
      individual test during development.
    - Automatic tests on memory leak are involved in autograding.
1. Your code must reproduce correct output with `make simple-run` and `make
   complex-run` as show in the sample runs!
1. To practice the memory management principals learned in class, you must use
   dynamic arrays to store lists of data in your classes. You classes must be
   memory leak free. Memory leakage will be checked and graded in autograding.
   You can run **make test-mem1** and **make test-mem2** to check memory
   problem for the Polygon and GIS classes respectively. (Not available for Mac
   OS user)
1. It is recommended to practice the good coding conventions in your code:
    1. Pass object by reference (make it const as necessary)
    1. Make **const** functions whenever applicable
1. **Particular tricky parts**
    - The ``Point`` class requires an operator overloading on the ``==``
      operator. Do not forget to implement it.
    - The ``void Polygon::parse`` and ``bool GIS::readfile`` methods should
      handle existing data. As they can both work with object with existing
      data in the dynamic array. Clean it up properly before reading in the new
      data.

## Submission Requirements:
1. All code must be added and committed to your local git repository.
2. All code must be pushed to the GitHub repository created when you "accepted"
   the assignment.
    1. After pushing, with `git push origin main`, visit the web URL of your
       repository to verify that your code is there. If you don't see the code
       there, then we can't see it either.
3. Your code must compile and run. The auto-grading tests will indicate your
   score for your submission.
    1. The auto-grading build should begin automatically when you push your code
       to GitHub.
    2. If your program will not compile, the graders will not be responsible for
       trying to test it.
    3. You should get an email regarding the status of your build, if it does
       not pass, keep trying.
4. Do not remove the data files!

## Important Notes:
- Projects will be graded on whether they correctly solve the problem, and
  whether they adhere to good programming practices.
- Projects must be received by the time specified on the due date.
- Please review the academic honesty policy.
    - Note that viewing another student's solution, whether in whole or in part,
      is considered academic dishonesty.
    - Also note that submitting code obtained through the Internet or other
      sources, whether in whole or in part, is considered academic dishonesty.
    - All programs submitted will be reviewed for evidence of academic
      dishonesty, and all violations will be handled accordingly.

## Grading Information:
- Breakdown
    + 80% GitHub Auto-grading
    + 10% Coding style (naming convention, neatness of code, etc)
    + 10% Code organization (modular design, separate files, headers, etc.)

## Checking Auto-grading Results:

After you push your code, GitHub will automatically run tests on your
submission. To view the results:

1. On your GitHub repository page, click the :arrow_forward: **Actions** tab at
   the top
2. Click on the most recent workflow run (it will show your commit message)
3. Wait until the run finishes (showing either ✅ or ❌)
4. Scroll down to "Autograding summary" section to see the summary
5. It will display:
   - **Points:** Your score (e.g., 10/10)
   - ✅ All tests passed! or ❌ Some tests failed
6. If tests failed, click the "Autograding" button above to see detailed logs:
   - Expand the **education/autograding@v1** step to see which tests failed
   - Look for :x: marks to identify specific failures
