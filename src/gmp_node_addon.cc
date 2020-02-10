#define RETURN_VALUE(info, value) info.GetReturnValue().Set(value)

#define LOCAL_STRING(str) Nan::New<String>(str).ToLocalChecked()

#define THROW_IF_NOT(condition, text) if (!(condition)) { return Nan::ThrowError(text); }

#include <gmp.h>
#include <nan.h>
#include <v8.h>

void MPF_Add(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();

    THROW_IF_NOT(info.Length() >= 2, "argument must be two");
    THROW_IF_NOT(info[0]->IsNumber(), "argument must be an number");
    THROW_IF_NOT(info[1]->IsNumber(), "argument must be an number");

    mpf_t sum, arg_0, arg_1;
    mpf_init(sum);
    mpf_init_set_d(arg_0, info[0]->NumberValue(context).FromJust());
    mpf_init_set_d(arg_1, info[1]->NumberValue(context).FromJust());
    mpf_add(sum, arg_0, arg_1);

    double result = mpf_get_d(sum);

    mpf_clear(sum);
    mpf_clear(arg_0);
    mpf_clear(arg_1);

    RETURN_VALUE(info, Nan::New<v8::Number>(result));
}

void MPF_Sub(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();

    THROW_IF_NOT(info.Length() >= 2, "argument must be two");
    THROW_IF_NOT(info[0]->IsNumber(), "argument must be an number");
    THROW_IF_NOT(info[1]->IsNumber(), "argument must be an number");

    mpf_t sum, arg_0, arg_1;
    mpf_init(sum);
    mpf_init_set_d(arg_0, info[0]->NumberValue(context).FromJust());
    mpf_init_set_d(arg_1, info[1]->NumberValue(context).FromJust());
    mpf_sub(sum, arg_0, arg_1);

    double result = mpf_get_d(sum);

    mpf_clear(sum);
    mpf_clear(arg_0);
    mpf_clear(arg_1);

    RETURN_VALUE(info, Nan::New<v8::Number>(result));
}

void MPF_Mul(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();

    THROW_IF_NOT(info.Length() >= 2, "argument must be two");
    THROW_IF_NOT(info[0]->IsNumber(), "argument must be an number");
    THROW_IF_NOT(info[1]->IsNumber(), "argument must be an number");

    mpf_t sum, arg_0, arg_1;
    mpf_init(sum);
    mpf_init_set_d(arg_0, info[0]->NumberValue(context).FromJust());
    mpf_init_set_d(arg_1, info[1]->NumberValue(context).FromJust());
    mpf_mul(sum, arg_0, arg_1);

    double result = mpf_get_d(sum);

    mpf_clear(sum);
    mpf_clear(arg_0);
    mpf_clear(arg_1);

    RETURN_VALUE(info, Nan::New<v8::Number>(result));
}

void MPF_Div(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();

    THROW_IF_NOT(info.Length() >= 2, "argument must be two");
    THROW_IF_NOT(info[0]->IsNumber(), "argument must be an number");
    THROW_IF_NOT(info[1]->IsNumber(), "argument must be an number");

    mpf_t sum, arg_0, arg_1;
    mpf_init(sum);
    mpf_init_set_d(arg_0, info[0]->NumberValue(context).FromJust());
    mpf_init_set_d(arg_1, info[1]->NumberValue(context).FromJust());
    mpf_div(sum, arg_0, arg_1);

    double result = mpf_get_d(sum);

    mpf_clear(sum);
    mpf_clear(arg_0);
    mpf_clear(arg_1);

    RETURN_VALUE(info, Nan::New<v8::Number>(result));
}

void MPF_Sqrt(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();

    THROW_IF_NOT(info.Length() >= 1, "argument must be one");
    THROW_IF_NOT(info[0]->IsNumber(), "argument must be an number");

    mpf_t sum, arg_0;
    mpf_init(sum);
    mpf_init_set_d(arg_0, info[0]->NumberValue(context).FromJust());
    mpf_sqrt(sum, arg_0);

    double result = mpf_get_d(sum);

    mpf_clear(sum);
    mpf_clear(arg_0);

    RETURN_VALUE(info, Nan::New<v8::Number>(result));
}

void MPF_Pow_ui(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();

    THROW_IF_NOT(info.Length() >= 2, "argument must be two");
    THROW_IF_NOT(info[0]->IsNumber(), "argument must be an number");
    THROW_IF_NOT(info[1]->IsUint32(), "argument must be an unsigned integer");

    mpf_t sum, arg_0;
    mpf_init(sum);
    mpf_init_set_d(arg_0, info[0]->NumberValue(context).FromJust());
    mpf_pow_ui(sum, arg_0, info[1]->Uint32Value(context).FromJust());

    double result = mpf_get_d(sum);

    mpf_clear(sum);
    mpf_clear(arg_0);

    RETURN_VALUE(info, Nan::New<v8::Number>(result));
}

void MPF_Abs(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();

    THROW_IF_NOT(info.Length() >= 1, "argument must be one");
    THROW_IF_NOT(info[0]->IsNumber(), "argument must be an number");

    mpf_t sum, arg_0;
    mpf_init(sum);
    mpf_init_set_d(arg_0, info[0]->NumberValue(context).FromJust());
    mpf_abs(sum, arg_0);

    double result = mpf_get_d(sum);

    mpf_clear(sum);
    mpf_clear(arg_0);

    RETURN_VALUE(info, Nan::New<v8::Number>(result));
}

void MPF_Neg(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();

    THROW_IF_NOT(info.Length() >= 1, "argument must be one");
    THROW_IF_NOT(info[0]->IsNumber(), "argument must be an number");

    mpf_t sum, arg_0;
    mpf_init(sum);
    mpf_init_set_d(arg_0, info[0]->NumberValue(context).FromJust());
    mpf_neg(sum, arg_0);

    double result = mpf_get_d(sum);

    mpf_clear(sum);
    mpf_clear(arg_0);

    RETURN_VALUE(info, Nan::New<v8::Number>(result));
}

void Init(v8::Local<v8::Object> exports) {
    v8::Local<v8::Context> context = exports->CreationContext();

    exports->Set(context,
        Nan::New("mpf_add").ToLocalChecked(),
        Nan::New<v8::FunctionTemplate>(MPF_Add)->GetFunction(context).ToLocalChecked()
    );
    exports->Set(context,
        Nan::New("mpf_sub").ToLocalChecked(),
        Nan::New<v8::FunctionTemplate>(MPF_Sub)->GetFunction(context).ToLocalChecked()
    );
    exports->Set(context,
        Nan::New("mpf_mul").ToLocalChecked(),
        Nan::New<v8::FunctionTemplate>(MPF_Mul)->GetFunction(context).ToLocalChecked()
    );
    exports->Set(context,
        Nan::New("mpf_div").ToLocalChecked(),
        Nan::New<v8::FunctionTemplate>(MPF_Div)->GetFunction(context).ToLocalChecked()
    );
    exports->Set(context,
        Nan::New("mpf_sqrt").ToLocalChecked(),
        Nan::New<v8::FunctionTemplate>(MPF_Sqrt)->GetFunction(context).ToLocalChecked()
    );
    exports->Set(context,
        Nan::New("mpf_pow_ui").ToLocalChecked(),
        Nan::New<v8::FunctionTemplate>(MPF_Pow_ui)->GetFunction(context).ToLocalChecked()
    );
    exports->Set(context,
        Nan::New("mpf_neg").ToLocalChecked(),
        Nan::New<v8::FunctionTemplate>(MPF_Neg)->GetFunction(context).ToLocalChecked()
    );
    exports->Set(context,
        Nan::New("mpf_abs").ToLocalChecked(),
        Nan::New<v8::FunctionTemplate>(MPF_Abs)->GetFunction(context).ToLocalChecked()
    );
}

NODE_MODULE(gmp_node_addon, Init);
