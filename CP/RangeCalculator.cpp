#include <windows.h>
#include <string>
#include <sstream>

// Global variables
HWND hInput1, hInput2, hResult;
HWND hCalculateButton;

// Function declarations
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
void AddControls(HWND);
long long calculateRangeSum(int start, int end);

// Entry point
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
    // Window class
    WNDCLASSW wc = {0};
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"RangeCalculatorClass";
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClassW(&wc))
        return -1;

    // Create window
    CreateWindowW(L"RangeCalculatorClass", 
                 L"Range Calculator", 
                 WS_OVERLAPPEDWINDOW | WS_VISIBLE, 
                 100, 100, 400, 300, 
                 NULL, NULL, hInst, NULL);

    // Message loop
    MSG msg = {0};
    while(GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

// Window procedure
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch(msg) {
        case WM_CREATE:
            AddControls(hwnd);
            break;
        case WM_COMMAND:
            if (LOWORD(wp) == 1) { // Calculate button clicked
                char input1[10], input2[10];
                GetWindowTextA(hInput1, input1, 10);
                GetWindowTextA(hInput2, input2, 10);

                int num1 = atoi(input1);
                int num2 = atoi(input2);

                if (num1 <= 0 || num2 <= 0) {
                    SetWindowTextA(hResult, "Please enter positive numbers only!");
                    break;
                }

                int start = (num1 < num2) ? num1 : num2;
                int end = (num1 > num2) ? num1 : num2;

                std::stringstream ss;
                ss << "Numbers: ";
                for (int i = start; i <= end; i++) {
                    ss << i << " ";
                }
                ss << "\nSum = " << calculateRangeSum(start, end);

                SetWindowTextA(hResult, ss.str().c_str());
            }
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProcW(hwnd, msg, wp, lp);
    }
    return 0;
}

// Add controls to window
void AddControls(HWND hwnd) {
    CreateWindowW(L"static", L"Enter First Number:", 
                 WS_VISIBLE | WS_CHILD,
                 20, 20, 120, 20,
                 hwnd, NULL, NULL, NULL);

    hInput1 = CreateWindowW(L"edit", L"", 
                          WS_VISIBLE | WS_CHILD | WS_BORDER,
                          150, 20, 100, 20,
                          hwnd, NULL, NULL, NULL);

    CreateWindowW(L"static", L"Enter Second Number:", 
                 WS_VISIBLE | WS_CHILD,
                 20, 50, 120, 20,
                 hwnd, NULL, NULL, NULL);

    hInput2 = CreateWindowW(L"edit", L"", 
                          WS_VISIBLE | WS_CHILD | WS_BORDER,
                          150, 50, 100, 20,
                          hwnd, NULL, NULL, NULL);

    hCalculateButton = CreateWindowW(L"button", L"Calculate", 
                                   WS_VISIBLE | WS_CHILD,
                                   150, 90, 100, 25,
                                   hwnd, (HMENU)1, NULL, NULL);

    hResult = CreateWindowW(L"edit", L"", 
                          WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,
                          20, 130, 340, 100,
                          hwnd, NULL, NULL, NULL);
}

// Calculate range sum
long long calculateRangeSum(int start, int end) {
    long long n = end - start + 1;
    return (n * (start + end)) / 2;
} 