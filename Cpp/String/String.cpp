#include"String.h"

int strInit(String* str) {
	if (str == NULL)
		return NullPointerError;
	str->HEAD = (char*)calloc(INIT_SIZE, sizeof(char));
	if (str->HEAD == NULL)
		return AllocError;

	str->init = 1;
	str->length = 0;
	str->capacity = INIT_SIZE;
	return str->init;
}
int strAssign(String* str, const char* s) {
	if (str == NULL)
		return NullPointerError;
	if (str->init != 1)
		return UnInitError;

	int s_len = strlen(s);
	if (s_len >= str->capacity) {
		char* newbase = NULL;
		newbase = (char*)realloc(str->HEAD, sizeof(char) * (s_len + ADD_SIZE));
		if (newbase == NULL)
			return AllocError;
		str->capacity = s_len + ADD_SIZE;
		str->HEAD = newbase;
	}
	str->HEAD = (char*)memcpy(str->HEAD, s, sizeof(char) * s_len);
	if (str->HEAD == NULL)
		return NullPointerError;
	str->HEAD[s_len] = '\0';
	str->length = s_len;

	return NoError;
}
int strLength(String* str, int* out) {
	if (str == NULL||str->HEAD == NULL)
		return NullPointerError;
	if (str->init != 1)
		return UnInitError;

	*out = str->length;
	return NoError;
}
int strClear(String* str) {
	if (str == NULL || str->HEAD == NULL)
		return NullPointerError;
	if (str->init != 1)
		return UnInitError;

	str->length = 0;
	str->HEAD[0] = '\0';
	return NoError;
}
int strDestroy(String* str) {
	if (str == NULL || str->HEAD == NULL)
		return NullPointerError;
	if (str->init != 1)
		return UnInitError;

	str->length = 0;
	str->capacity = 0;
	str->init = 0;
	free(str->HEAD);
	str->HEAD = NULL;
	return NoError;
}
int strConcat(String* str1, String* str2) {
	if (str1 == NULL || str1->HEAD == NULL)
		return NullPointerError;
	if (str1->init != 1 || str2->init != 1)
		return UnInitError;

	if (str2 == NULL || str2->HEAD == NULL)
		return NoError;

	int s1_len = str1->length;
	int s2_len = str2->length;
	int s1_s2_len = str1->length + str2->length;
	if (s1_s2_len >= str1->capacity) {
		char* newbase = NULL;
		newbase = (char*)realloc(str1->HEAD, sizeof(char) * (s1_s2_len + ADD_SIZE));
		if (newbase == NULL)
			return AllocError;
		str1->capacity = s1_s2_len + ADD_SIZE;
		str1->HEAD = newbase;
	}
	memcpy(str1->HEAD + s1_len, str2->HEAD, sizeof(char) * s2_len);
	if (str1->HEAD == NULL)
		return NullPointerError;
	str1->HEAD[s1_s2_len] = '\0';
	str1->length = s1_s2_len;

	return NoError;
}
int strSubString(String* str, String* out, int position, int len) {
	if (str == NULL || str->HEAD == NULL)
		return NullPointerError;
	if (out == NULL || out->HEAD == NULL)
		return NullPointerError;
	if (str->init != 1 || out->init != 1)
		return UnInitError;

	if (len <= 0)
		return DataIllegalError;
	if (position >= str->length || position <= 0)
		return DataIllegalError;

	out->length = 0;
	out->capacity = 0;
	out->init = 0;
	free(out->HEAD);
	out->HEAD = NULL;

	char* newbase = NULL;
	newbase = (char*)realloc(out->HEAD, sizeof(char) * (len + ADD_SIZE));
	if (newbase == NULL)
		return AllocError;
	out->capacity = len + ADD_SIZE;
	out->HEAD = newbase;
	memcpy(out->HEAD, str->HEAD+position, sizeof(char) * len);
	if (out->HEAD == NULL)
		return NullPointerError;
	out->HEAD[len] = '\0';
	out->length = len;

	return NoError;
}
int strIndex(String* str, String* t, int* out) {
	if (str == NULL || str->HEAD == NULL)
		return NullPointerError;
	if (str->init != 1)
		return UnInitError;
	if (t == NULL || t->HEAD == NULL) {
		*out = 0;
		return NoError;
	}

	if (t->length > str->length) {
		*out = -1;
		return NoError;
	}

	char* p_str = &(str->HEAD[0]);
	char* p_t = &(t->HEAD[0]);

	int len_str = str->length;
	int len_t = t->length;

	int fail = 0;
	int success = 0;
	for (int i = 0; i < len_str - len_t + 1; i++) {
		for (int j = 0; j < len_t; j++) {
			if (str->HEAD[j + i] != t->HEAD[j]) {
				fail = 1;
				break;
			}
			if (j == len_t - 1)
				success = 1;
		}
		if (fail == 1) {
			fail = 0;
			*out = -1;
			continue;
		}
		else if(success == 1){
			*out = i;
			break;
		}
	}
	return NoError;
}
int strGetNext(String* str, int* next) {
	if (str == NULL || str->HEAD == NULL)
		return NullPointerError;
	if (str->init != 1)
		return UnInitError;

	next[0] = -1;
	int k = -1;
	for (int i = 1; i < str->length; i++)
	{
		while (k > -1 && str->HEAD[k + 1] != str->HEAD[i])
			k = next[k];
		if (str->HEAD[k + 1] == str->HEAD[i])
			k++;
		next[i] = k;
	}
	return NoError;
}

