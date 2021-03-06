/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "updater_ui.h"
#include <cstdio>
#ifdef HAVE_TERMIOS_H
#include <termios.h>
#elif defined(HAVE_TERMIO_H)
#include <termio.h>
#endif

#include "log.h"
#include "securec.h"
#include "surface_dev.h"
#include "utils/hdf_log.h"

namespace OHOS {
namespace HDI {
namespace Battery {
namespace V1_0 {
constexpr int LABEL_HEIGHT = 15;
constexpr int LABEL0_OFFSET = 0;
constexpr int LABEL2_OFFSET = 1;

void TextLabelInit(TextLabel *t, const std::string &text, struct Bold bold,
    struct FocusInfo focus, View::BRGA888Pixel color)
{
    HDF_LOGD("%{public}s enter", __func__);
    if (t != nullptr) {
        t->SetText(text.c_str());
        t->SetOutLineBold(bold.top, bold.bottom);
        t->OnFocus(focus.focus);
        t->SetBackgroundColor(&color);
        t->SetFocusAble(focus.focusable);
    }
}

void MenuItemInit(int height, int width, View::BRGA888Pixel bgColor, Frame *g_hosFrame)
{
    HDF_LOGD("%{public}s enter", __func__);
    TextLabel *g_textLabel0;
    TextLabel *g_textLabel2;

    if (g_hosFrame == nullptr) {
        HDF_LOGD("%{public}s enter, Frame is null.", __func__);
        return;
    }
    g_textLabel0 = new TextLabel(0, height * LABEL0_OFFSET / LABEL_HEIGHT, width, height /
        LABEL_HEIGHT, g_hosFrame);
    struct FocusInfo info {true, true};
    struct Bold bold {true, false};
    TextLabelInit(g_textLabel0, "Reboot to normal system", bold, info, bgColor);
    if (!g_textLabel0) {
        HDF_LOGD("%{public}s enter, g_textLabel0 is null.", __func__);
        return;
    }

    g_textLabel2 = new TextLabel(0, height * LABEL2_OFFSET / LABEL_HEIGHT, width, height /
        LABEL_HEIGHT, g_hosFrame);
    info = {false, true};
    bold = {false, false};
    TextLabelInit(g_textLabel2, "Userdata reset", bold, info, bgColor);
    if (!g_textLabel2) {
        HDF_LOGD("%{public}s enter, g_textLabel2 is null.", __func__);
        return;
    }
}
}  // namespace V1_0
}  // namespace Battery
}  // namespace HDI
}  // namespace OHOS
