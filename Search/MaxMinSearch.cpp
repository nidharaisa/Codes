//
//  MaxMinSearch.cpp
//  CrackingCodeInterview
//
//  Created by Raisa Islam on 3/11/18.
//  Copyright © 2018 Raisa Islam. All rights reserved.
//

#include <iostream>
#include <stdio.h>

int searchMin(int arr[], int start, int end)
{
	if(start == end) {
		return arr[end];
	}
	
	if ( (start+1) == end) {
		return std::min(arr[start], arr[end]);
	}
	
	int mid = (start+end)/2;
	if(arr[mid]<arr[mid+1] && arr[mid]<arr[mid-1]) {
		return arr[mid];
	}
	
	if (arr[mid]>arr[mid+1] && arr[mid]<arr[mid-1]){
		return searchMin(arr, mid+1, end);
	}
	else {
		return searchMin(arr, start, mid-1);
	}
}

int searchMax(int arr[], int start, int end)
{
	if(start == end) {
		return arr[end];
	}
	
	if ( (start+1) == end) {
		return std::max(arr[start], arr[end]);
	}
	
	int mid = (start+end)/2;
	if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]) {
		return arr[mid];
	}
	
	if (arr[mid]>arr[mid+1] && arr[mid]<arr[mid-1]){
		return searchMax(arr, start, mid-1);
	}
	else {
		return searchMax(arr, mid+1, end);
	}
}

/*
 * Find the maximum and minimum element in an array which is first increasing and then decreasing
 */
int main() {
	
		// int arr[] = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
		// int arr[] = {8, 10, 20, 80, 100, 200, 400, 500, 70, 50};
	int arr[] = {60, 10, 70, 80, 100, 501};
	
	int len = sizeof(arr)/sizeof(arr[0]);
	
	std::cout << "Max : " << searchMax(arr, 0 , len-1) << " Min : " << searchMin(arr, 0 , len-1) << std::endl;
	
	return 0;
}
